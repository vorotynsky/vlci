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

#include <string>
#include <set>
#include <vector>


TEST_CASE("equality of variables", "[ast]")
{
    LambdaContainer lambdas;

    REQUIRE(lambdas.names.size() > 1);

    for (auto name : lambdas.names)
        REQUIRE((Variable(name) == (Variable(name))));
}

TEST_CASE("inequality of variables", "[ast]")
{
    LambdaContainer lambdas;
    std::vector<Variable> variables;

    REQUIRE(lambdas.names.size() > 1);
    
    for (const auto &name : lambdas.names)
        variables.push_back(Variable(name));

    for (int i = 1; i < variables.size(); ++i)
        for (int j = 0; j < i; ++j)
            CHECK(variables[i] != variables[j]);
}
