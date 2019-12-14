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

#include <catch2/catch.hpp>

#include <vector>
#include "../../vlcp/Parser/VectorSlice/VectorSlice.hpp"

TEST_CASE("empty vector", "[vector slice]") 
{
    std::vector<int> vector = {};
    REQUIRE(vector.size() == 0);
    VectorSlice<int> slice(&vector, 0, 0);

    CHECK(slice.size() == 0);
    CHECK(slice.begin() == slice.end());
}

TEST_CASE("empty vector out of range", "[vector slice]")
{
    std::vector<int> vector = {};
    REQUIRE(vector.size() == 0);

    CHECK_NOTHROW(VectorSlice<int>(&vector, 0, 0));

    for (int i = -3; i < 3; i++)
    {
        for (int j = -3; j < 3; j++)
        {
            if (i == j == 0)
                break;
            CHECK_THROWS(new VectorSlice<int>(&vector, i, j));
        }
    }
}

TEST_CASE("nullptr instead of vector", "[vector slice]")
{
    CHECK_THROWS(VectorSlice<int>(nullptr, 0, 0));
}
