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

#include "../../vlcp/vlcp.h"
#include "lambdas.hpp"

#include <catch2/catch.hpp>

#include <vector>
#include <cstring>


TEST_CASE("equality of application", "[ast]")
{
    LambdaContainer lambdas = LambdaContainer();
    for (auto lambda1 : lambdas.lambdas)
        for (auto lambda2 : lambdas.lambdas)
            CHECK(Application(lambda1, lambda2) == Application(lambda1, lambda2));
}

TEST_CASE("inequality of application", "[ast]")
{
    LambdaContainer lambdas = LambdaContainer();
    std::vector<Application> applications;

    for (const auto lambda1 : lambdas.lambdas)
        for (const auto lambda2 : lambdas.lambdas)
            applications.push_back(Application(lambda1, lambda2));

    for (int i = 1; i < applications.size(); ++i)
        for (int j = 0; j < i; ++j)
            CHECK(applications[i] != applications[j]);
}
