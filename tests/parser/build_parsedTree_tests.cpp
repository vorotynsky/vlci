// Vorotynsky's lambda calculus interpreter 
// Copyright (C) 2020  Vorotynsky Maxim 
//  
// This program is free software: you can redistribute it and/or modify 
// it under the terms of the GNU General Public License as published by 
// the Free Software Foundation, either version 3 of the License, 
// or (at your option) any later version. 
//  
// This program is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
//  
// You should have received a copy of the GNU General Public License 
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <catch2/catch.hpp>

#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "../../vlcp/vlcp.h"

TEST_CASE("empty lexer, empty parsed tree", "[bracket parser]")
{
    std::istringstream ss("");
    Lexer lexer(ss);

    auto tree = ParsedTree::build(lexer);
    REQUIRE(tree != nullptr);
    REQUIRE(tree->getTree() != nullptr);
    auto slice = tree->getTree()->tokens;
    CHECK(slice.begin() == slice.end());

    delete tree;
}

TEST_CASE("no brackets in multiline", "[bracket parser]")
{
    std::string expressions = 
        "\\x.x \n"
        "\\x y. x \n"
        "\\x y. y x \n"
        "f x y \n"
        "\\x y. f x y \n"
        "f x \\x. x \n";
    std::istringstream ss(expressions);
    Lexer lexer(ss);

    const size_t count = std::count(expressions.begin(), expressions.end(), '\n');

    for (size_t i = 0; i < count; i++)
    {
        auto tree = ParsedTree::build(lexer);
        lexer.moveNext();

        REQUIRE(tree != nullptr);
        REQUIRE(tree->getTree() != nullptr);
        CHECK(tree->getTree()->childs.size() == 0);

        auto out_token = *(tree->getTree()->tokens.end() - 1); // token after expression
        CHECK(out_token.getType() != Token::LF); // '\n' isn't in Expression

        delete tree;
    }
}

TEST_CASE("one level of brackets", "[bracket parser]")
{
    std::string expressions = 
        "(\\x.x) a \n"
        "(\\x y. x) a \n"
        "\\x y. (y x) \n"
        "f (x y) \n"
        "\\x y. f (x y) \n"
        "f x (\\x. x) \n";
    std::istringstream ss(expressions);
    Lexer lexer(ss);

    const size_t count = std::count(expressions.begin(), expressions.end(), '\n');

    for (size_t i = 0; i < count; i++)
    {
        auto tree = ParsedTree::build(lexer);
        lexer.moveNext();

        REQUIRE(tree != nullptr);
        REQUIRE(tree->getTree() != nullptr);

        auto out_token = *(tree->getTree()->tokens.end() - 1);
        CHECK(out_token.getType() != Token::LF);

        for (auto child : tree->getTree()->childs)
        {
            auto nchild = dynamic_cast<const ParsedTree::Node *>(child);
            REQUIRE(nchild != nullptr);
            CHECK(nchild->childs.size() == 0);

            auto first_token = *(nchild->tokens.begin());
            auto last_token  = *(nchild->tokens.end() - 1);
            CHECK(first_token.getType() != Token::LEFT_BRACKET);
            CHECK(last_token.getType() != Token::RIGHT_BRACKET);
        }
        

        delete tree;
    }
}

TEST_CASE("y-combinator brackets", "[bracket parser]")
{
    std::string omega = "\\x.f (x x)";
    std::string y = "\\f.(" + omega + ")(" + omega + ")";
    std::istringstream ss(y);
    Lexer lexer(ss);

    auto tree = ParsedTree::build(lexer);
    REQUIRE(tree != nullptr);
    REQUIRE(tree->getTree() != nullptr);
    CHECK(tree->getTree()->childs.size() == 2);

    std::vector<Token> omega_tokens;
    {
        std::istringstream ss(omega);
        Lexer lexer(ss);
        lexer.moveNext();
        while (lexer.current().getType() != Token::EoF)
        {
            omega_tokens.push_back(lexer.current());
            lexer.moveNext();
        }
    }

    for (auto child : tree->getTree()->childs)
    {
        auto nchild = dynamic_cast<const ParsedTree::Node *>(child);
        auto itokens = nchild->tokens.begin();
        
        CHECK(std::equal(omega_tokens.begin(), omega_tokens.end(), itokens));
    }

    delete tree;
}

TEST_CASE("wrong brackets order", "[bracket parser]")
{
    std::string expressions =
        "(\\x.x\n"
        "\\x.x) a\n"
        "((\\x.x) a\n"
        "(\\x.x) a )\n"
        ")()(\n";
    std::istringstream ss(expressions);
    Lexer lexer(ss);

    const size_t count = std::count(expressions.begin(), expressions.end(), '\n');

    for (size_t i = 0; i < count; i++)
    {
        CHECK_THROWS(ParsedTree::build(lexer));

        while (lexer.current() != Token::LF)
            lexer.moveNext();
        lexer.moveNext();
    }
    
}
