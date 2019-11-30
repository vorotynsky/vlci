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

#pragma once

#include "lambda.hpp"
#include "variable.hpp"

/// @todo make a function that builds a tree where free variables substituted to bounded.

/**
 * @brief Abstraction of lambda term.
 * 
 * Function definition (M is a lambda term). The variable x becomes bound in the expression.
 * 
 * \f[(\lambda v. M) \f]
 */
class Abstraction final : public LambdaExpression 
{
public:
    /**
     * @brief The bounded variable lambda term.
     */
    class BoundedVariable final : public Variable 
    {
    private:
        const Abstraction *linkedAbstraction;
    protected:
        bool Equals(const LambdaExpression &other) const override;

    public:
        /**
         * @brief Construct a new Bounded Variable object
         * 
         * @param name the name of the new bounded variable.
         * @param abstraction the pointer to abstraction with the variable will be linked.
         */
        BoundedVariable(const std::string &name, const Abstraction *abstraction);

        virtual ~BoundedVariable();

        /**
         * @brief Get the linked Abstraction object.
         */
        Abstraction const *getAbstraction() const;
    };

private:
    const BoundedVariable abstractVariable;
    const LambdaExpression *lambda;
protected:
    bool Equals(const LambdaExpression &other) const override;

public:
    /**
     * @brief Construct a new Abstraction object
     * 
     * @param lambda lambda term (`M`).
     * @param var variable ('v') for make bounded variable. 
     */
    Abstraction(const LambdaExpression *lambda, const Variable &var);

    /**
     * @brief Get the bounded variable of the current abstraction.
     * 
     * @warning A bounded variable is a field of this class. After destroying an abstraction node the bounded variable will be unreachable.
     * 
     * @return BoundedVariable const* bounded variable that linked to the current object.
     */
    BoundedVariable const *getBoundedVariable() const;

    virtual ~Abstraction();
};
