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

/**
 * @file lambda.hpp
 * @author Vorotynsky Maxim
 * @date 2019
 * @copyright GNU General Public License
 * 
 * @brief header file for lambda calculus abstract syntax tree.
 * 
 * Lambda = Variable
 *        | Application (Lambda Lambda)
 *        | Abstraction (\ variable. lambda)
 */


#pragma once

#include <string>

/**
 * @brief The base class for lambda expression AST-node.
 */
class LambdaExpression {
protected:
    LambdaExpression() = default;

    friend bool operator==(const LambdaExpression &left, const LambdaExpression &right);
    friend bool operator!=(const LambdaExpression &left, const LambdaExpression &right);

    virtual bool Equals(const LambdaExpression &other) const = 0;
public:
    virtual ~LambdaExpression() = default;
};
