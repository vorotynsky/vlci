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


class Abstraction final : public LambdaExpression {

    class BoundedVariable final : public Variable {
    private:
        const Abstraction *linkedAbstraction;
    public:
        BoundedVariable(const std::string &name, const Abstraction *abstraction);

        ~BoundedVariable() override;
    };

private:
    const BoundedVariable abstractVariable;
    const LambdaExpression *lambda;
public:
    Abstraction(const LambdaExpression *lambda, const Variable &var);

    const BoundedVariable *getBoundedVariable() const;

    ~Abstraction() override;
};
