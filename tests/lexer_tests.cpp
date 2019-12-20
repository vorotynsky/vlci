// Vorotynsky's lambda calculus interpreter
// Copyright (C) 2019  Vorotynsky Maxim
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
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
#include <string>
#include "../vlcp/vlcp.h"


TEST_CASE("empty input", "[lexer]") 
{
    std::istringstream input("");
    Lexer lexer(input);

    CHECK(lexer.getPossition() == 0);
    CHECK(lexer.current() == Token());

    Token eof = Token(Token::EoF);
    for (int i = 0; i < 16; i++) 
    {
        lexer.moveNext();
        CHECK(lexer.getPossition() == 0);
        CHECK(lexer.current() == eof);
    }
}

TEST_CASE("one char input", "[lexer]") 
{
    const std::map<char, Token> charToken = 
    {
        { '(' ,  Token(Token::LEFT_BRACKET)  },
        { ')' ,  Token(Token::RIGHT_BRACKET) },
        { '\\',  Token(Token::LAMBDA)       },
        { '.' ,  Token(Token::DOT)          },
        { '\0',  Token(Token::EoF)          },
        { '\n',  Token(Token::LF)           }
    };

    for (const auto el : charToken)
    {
        std::string instring(1, el.first);
        std::istringstream input(instring);

        Lexer lexer(input);
        lexer.moveNext();

        CHECK(lexer.current() == el.second);    
    }
}

TEST_CASE("name token", "[lexer]") 

{
    std::string expected = "itsname";
    std::istringstream input (" \t  " + expected + " \r\n      ");

    Lexer lexer(input);
    lexer.moveNext();

    Token name_token = Token(expected);
    CHECK(lexer.current() == name_token);
}

TEST_CASE("name in brackets", "[lexer]") 
{
    std::string expected = "itsname";
    std::istringstream input ("(" + expected + ")");

    std::vector<Token> tokens = 
        { Token(Token::LEFT_BRACKET), Token(expected), Token(Token::RIGHT_BRACKET) };
    
    Lexer lexer(input);

    for (auto token : tokens) 
    {
        lexer.moveNext();
        CHECK(lexer.current() == token);
    }
}

TEST_CASE("y-combinator", "[lexer]")
{
    std::string term = "\\f.(\\x.f(x x))(\\x.f(x x))";
    std::istringstream input (term);
    std::vector<Token> tokens;

    {
        Token lambda = Token(Token::LAMBDA);
        Token dot = Token(Token::DOT);
        Token lb = Token(Token::LEFT_BRACKET);
        Token rb = Token(Token::RIGHT_BRACKET);
        std::string f_str = "f", x_str = "x";
        Token f = Token(f_str);
        Token x = Token(x_str);

        tokens = {lambda, f, dot, lb, lambda, x, dot, f, lb, x, x, rb, rb, lb, lambda, x, dot, f, lb, x, x, rb, rb};
    }

    Lexer lexer(input);

    CHECK(lexer.getPossition() == 0);
    for (int i = 0; i < tokens.size(); ++i)
    {
        lexer.moveNext();
        CHECK(lexer.getPossition() == i);
        CHECK(lexer.current() == tokens[i]);    
    }
}
