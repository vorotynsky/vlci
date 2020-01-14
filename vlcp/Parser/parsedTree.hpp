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

#pragma once

#include "VectorSlice/VectorSlice.hpp"
#include "../Lexer/tokens.hpp"
#include "../Lexer/lexer.hpp"
#include "../AST/lambda.hpp"

class ParsedTree final
{
public:

    struct Node : LambdaExpression
    {
        const VectorSlice<Token> tokens;
        const std::vector<const LambdaExpression *> childs;

        Node(const VectorSlice<Token> &tokens, const std::vector<const LambdaExpression *> &childs);
        virtual ~Node() = default;
    
    protected:
        bool Equals(const LambdaExpression &other) const override;
    };

    const Node *getTree() const;

    static ParsedTree* build(Lexer &lexer);

    ParsedTree(const ParsedTree &tree) = delete;
    ~ParsedTree();

private:
    ParsedTree() = default;

    std::vector<Token> tokens;
    Node *tree;
};
