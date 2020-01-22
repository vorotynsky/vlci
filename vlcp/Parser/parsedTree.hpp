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


/**
 * @brief The class that contains a parsed tree by brackets.
 * 
 * It contains data such as:
 *  - parsed tokens,
 *  - the root of the parsed tree.
 */
class ParsedTree final
{
public:

    /// @brief The parsed tree node contains a token slice and its children.
    struct Node : LambdaExpression
    {
        const VectorSlice<Token> tokens;
        const std::vector<const LambdaExpression *> childs;

        /**
         * @brief Construct a new Node object.
         * 
         * @param tokens tokens that will be associated with the node.
         * @param childs childs of the new node.
         */
        Node(const VectorSlice<Token> &tokens, const std::vector<const LambdaExpression *> &childs);
        virtual ~Node() = default;
    
    protected:
        bool Equals(const LambdaExpression &other) const override;
    };

    /**
     * @brief Get the root of parsed tree.
     * 
     * @return const Node* const pointer to the root.
     */
    const Node *getTree() const;

    /**
     * @brief Parse the bracket tree from a Lexer.
     * 
     * Reads a one line with a expression.
     * 
     * @throw std::domain_error if the expression has wrong bracket order.
     * 
     * @param lexer The lexer with one or more rows.
     * @return ParsedTree* builded parsed tree. `not null`
     */
    static ParsedTree* build(Lexer &lexer);

    /// @brief The ParsedTree can't be copied.
    ParsedTree(const ParsedTree &tree) = delete;
    ~ParsedTree();

private:
    ParsedTree() = default;

    std::vector<Token> tokens;
    Node *tree;
};
