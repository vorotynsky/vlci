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

#include "abstraction.hpp"

#include <stdexcept>

Abstraction::Abstraction(const LambdaExpression *lambda, const Variable &var) 
    : LambdaExpression(), 
      abstractVariable(var.getName(), this) 
{
    this->lambda = lambda ? lambda : throw std::invalid_argument("lambda is null.");
}

Abstraction::~Abstraction() = default;

Abstraction::BoundedVariable const *Abstraction::getBoundedVariable() const 
{
    return &(this->abstractVariable);
}

Abstraction::BoundedVariable::BoundedVariable(const std::string &name, const Abstraction *abstraction)
    : Variable(name) 
{
    this->linkedAbstraction = abstraction ? abstraction : throw std::invalid_argument("abstraction is null.");
}

Abstraction::BoundedVariable::~BoundedVariable() = default;

Abstraction const *Abstraction::BoundedVariable::getAbstraction() const 
{
    return this->linkedAbstraction;
}
