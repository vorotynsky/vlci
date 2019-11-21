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

#include "application.hpp"

#include <stdexcept>

Application::Application(const LambdaExpression *base, const LambdaExpression *argument) 
    : LambdaExpression() 
{
    this->base     = base     ? base     : throw std::invalid_argument("base is null.");
    this->argument = argument ? argument : throw std::invalid_argument("argument is null.");
}

bool Application::Equals(const LambdaExpression &other) const {
    auto aother = static_cast<const Application &> (other);

    return base == aother.base
        && argument == aother.argument;
}

Application::~Application() = default;
