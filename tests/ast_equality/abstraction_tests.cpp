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

#include <set>
#include <vector>
#include <string>
#include <cstring>


TEST_CASE("equality of abstraction", "[ast]")
{
    LambdaContainer lambdas = LambdaContainer();

    REQUIRE(lambdas.lambdas.size() > 1);
    REQUIRE(lambdas.names.size() > 1);

    for (auto lambda1 : lambdas.lambdas)
    {
        for (auto name: lambdas.names)
        {
            auto a1 = Abstraction(lambda1, Variable(name));
            auto a2 = Abstraction(lambda1, Variable(name));

            CHECK(a1 == a2);
        }
    }
}

TEST_CASE("inequality of abstraction", "[ast]")
{
    LambdaContainer lambdas = LambdaContainer();
    std::vector<Abstraction> abstractions;
    
    REQUIRE(lambdas.lambdas.size() > 1);
    REQUIRE(lambdas.names.size() > 1);

    for (auto lambda1 : lambdas.lambdas)
        for (auto name : lambdas.names)
            abstractions.push_back(Abstraction(lambda1, Variable(name)));

    for (int i = 1; i < abstractions.size(); ++i)
        for (int j = 0; j < i; ++j)
            CHECK(abstractions[i] != abstractions[j]);
}
