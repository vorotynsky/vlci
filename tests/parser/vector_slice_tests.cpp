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

TEST_CASE("one element vector slice", "[vector slice]")
{
    std::vector<int> vector = {1, 2, 3, 4, 5, 6, 7, 8};
    REQUIRE(vector.size() > 1);

    for (int i = 0; i < vector.size() - 1; i++)
    {
        VectorSlice<int> slice(&vector, i, i + 1);
        CHECK(*slice.begin() == vector[i]);
        CHECK(std::distance(slice.begin(), slice.end()) == 1);
        CHECK(slice.size() == 1);
    }
}

TEST_CASE("vector slice tests", "[vector slice]")
{
    std::vector<int> vector = {1, 2, 3, 4, 5, 6, 7, 8};
    REQUIRE(vector.size() > 1);

    for (int i = 0; i < vector.size() - 1; i++)
    {
        for (int j = i + 1; j < vector.size(); j++)
        {
            VectorSlice<int> slice(&vector, i, j);
            
            auto it = slice.begin();
            int count  = 0;
            for (int idx = i; idx < j; idx++)
            {
                CHECK(*it == vector[idx]);
                it++;
                count++;
            }
            CHECK(count == slice.size());
            CHECK(it == slice.end());
        }
    }
}

TEST_CASE("vector, out of range", "[vector slice]")
{
    std::vector<int> vector = {1, 2, 3, 4, 5, 6, 7, 8};
    REQUIRE(vector.size() > 1);
    const int delta = 1;

    std::vector<int> indexes(2 * delta);
    std::iota(indexes.begin(), indexes.begin() + delta, -delta);
    std::iota(indexes.begin() + delta, indexes.end(), vector.size());
    
    for (int i : indexes)
        for (int j : indexes)
            CHECK_THROWS(VectorSlice<int>(&vector, i, j));
}
