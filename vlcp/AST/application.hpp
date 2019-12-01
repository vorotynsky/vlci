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

/**
 * @brief Application of 2 lambda terms.
 * 
 * Applying a function to an argument, \f$ (M N) \f$, where `M` and `N` are lambda terms.
 */
class Application final : public LambdaExpression 
{
private:
    const LambdaExpression *base;
    const LambdaExpression *argument;

protected:
    bool Equals(const LambdaExpression &other) const override;

public:
    /**
     * @brief Construct a new Application object.
     * 
     * @param base function (`M`) lambda term.
     * @param argument argument (`N`) lambda term.
     */
    Application(const LambdaExpression *base, const LambdaExpression *argument);

    virtual ~Application();
};
