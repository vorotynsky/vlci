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
    /**
     * @brief Construct a new Lambda Expression object.
     */
    LambdaExpression() = default;

    friend bool operator==(const LambdaExpression &left, const LambdaExpression &right);
    friend bool operator!=(const LambdaExpression &left, const LambdaExpression &right);

    /**
     * @brief Virtual function for compare 2 lambda expressions. Used in `operator==`.
     * 
     * @return `false` if the specified tokens are equal to the current tokens; otherwise, `true`.
     */
    virtual bool Equals(const LambdaExpression &other) const = 0;
public:
    virtual ~LambdaExpression() = default;
};

/**
 * @brief Determines whether two tokens instances are equal.
 * 
 * Compare lambdas by value without reduction.
 * 
 * @param left A lambda expression.
 * @param right A lambda expression.
 * @return true if left and right labda expression are equals.
 * @return false if left and right lambda expression are not equals.
 */
bool operator==(const LambdaExpression &left, const LambdaExpression &right);

/**
 * @brief Determines whether two tokens instances are not equal.
 * 
 * Compare lambdas by value without reduction.
 * 
 * @param left A lambda expression.
 * @param right A lambda expression.
 * @return true if left and right labda expression are not equals.
 * @return false if left and right lambda expression are equals.
 */
bool operator!=(const LambdaExpression &left, const LambdaExpression &right);
