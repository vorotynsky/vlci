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
#include <stdexcept>

template<typename T, typename Allocator = std::allocator<T>>
class VectorSlice final
{
private:
    const std::vector<T, Allocator> *vector;
    const int v_begin, v_end;

public:
    using iterator = typename std::vector<T, Allocator>::const_iterator;

    VectorSlice(const std::vector<T, Allocator> *source, int begin, int end);

    const std::vector<T, Allocator> *getVector() const;
    std::size_t size() const;
    
    const T &operator[] (int id) const;

    iterator begin() const;
    iterator end() const;
};

// REALIZATION

template<typename T, typename Allocator>
VectorSlice<T, Allocator>::VectorSlice(const std::vector<T, Allocator> *source, int begin, int end)
    : vector(source), v_begin(begin), v_end(end) 
{
    if (source == nullptr)
        throw std::invalid_argument("source is null.");
    
    if (((source->size() <= begin || source->size() <= end) && source->size() != 0) || begin < 0 || end < 0 || begin > end)
        throw std::out_of_range("begin/end is is out of range");
}

template<typename T, typename Allocator>
const std::vector<T, Allocator> *VectorSlice<T, Allocator>::getVector() const 
{
    return this->vector;
}

template<typename T, typename Allocator>
std::size_t VectorSlice<T, Allocator>::size() const 
{
    return v_end - v_begin;
}

template<typename T, typename Allocator>
const T &VectorSlice<T, Allocator>::operator[](int id) const 
{
    return this->vector[v_begin + id];
}

template<typename T, typename Allocator>
typename VectorSlice<T, Allocator>::iterator VectorSlice<T, Allocator>::begin() const 
{
    return this->vector->begin() + v_begin;
}

template<typename T, typename Allocator>
typename VectorSlice<T, Allocator>::iterator VectorSlice<T, Allocator>::end() const 
{
    return this->vector->begin() + v_end;
}
