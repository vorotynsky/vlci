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

#include <vector>
#include <iterator>

template<typename T>
class VectorSlice final
{

private:
    const std::vector<T> *vector;
    const int v_begin, v_end;
public:

    using iterator = typename std::vector<T>::iterator;

    VectorSlice(const std::vector<T> *source, int begin, int end);

    const std::vector<T> *getVector() const;
    std::size_t size() const;
    
    const T &operator[] (int id) const;

    iterator begin() const;
    iterator end() const;
};
