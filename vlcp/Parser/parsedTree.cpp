// Vorotynsky's lambda calculus interpreter 
// Copyright (C) 2020  Vorotynsky Maxim 
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

#include "parsedTree.hpp"

ParsedTree::Node::Node(const VectorSlice<Token> &tokens, const std::vector<const LambdaExpression *> &childs)
    : LambdaExpression(), tokens(tokens), childs(childs) { }

bool ParsedTree::Node::Equals(const LambdaExpression &other) const
{
    auto nother = static_cast<const ParsedTree::Node &>(other);

    return nother.childs == childs
        && (nother.tokens.begin() == tokens.begin()
        &&  nother.tokens.end() == tokens.end());  // todo : overload operator== for VectorSlice
}

const ParsedTree::Node *ParsedTree::getTree() const
{
    return this->tree;
}

// build

inline bool isEnd(Lexer &lexer)
{
    Token::TokenType type = lexer.current().getType();
    return type == Token::EMPTY || type == Token::EoF || type == Token::LF;
}

ParsedTree::Node *buildNode(Lexer &lexer, std::vector<Token> &readedTokens)
{
    const int start_index = readedTokens.size();
    if (lexer.current().getType() == Token::EMPTY)
        lexer.moveNext();

    if (isEnd(lexer))
        return nullptr;

    std::vector<const LambdaExpression *> childs;
    while (lexer.current().getType() != Token::RIGHT_BRACKET)
    {
        if (lexer.current().getType() == Token::LEFT_BRACKET)
            childs.push_back(buildNode(lexer, readedTokens));
        if (isEnd(lexer))
            throw std::domain_error("expression is not complete.");
        
        readedTokens.push_back(lexer.current());
        lexer.moveNext();
    }

    auto slice = VectorSlice<Token>(&readedTokens, start_index, readedTokens.size());
    return new ParsedTree::Node(slice, childs);
}

ParsedTree *ParsedTree::build(Lexer &lexer)
{
    ParsedTree *tree = new ParsedTree();
    tree->tree = buildNode(lexer, (tree->tokens));
    return tree;
}

void free_tree(const ParsedTree::Node *tree)
{
    if (tree == nullptr)
        return;
    for (auto t : tree->childs)
    {
        auto nt = dynamic_cast<const ParsedTree::Node *>(t);
        free_tree(nt);
    }
    delete tree;
}

ParsedTree::~ParsedTree()
{
    free_tree(tree);
}
