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

#include "lambdas.hpp"

LambdaContainer::LambdaContainer()
{
    this->lambdas = {
        new Variable("a"), new Variable("x"), new Variable("y"), new Variable("z"), // variables
        new Application(&x_var, &y_var),  // x y
        new Abstraction(&x_var, Variable("x"))   // \x.x
    };
    this->names = {"x", "y", "z", "var1", "var2", "WhatAboutCamelCase"};
}

LambdaContainer::~LambdaContainer()
{
    for (auto lambda : lambdas)
        delete lambda;
}