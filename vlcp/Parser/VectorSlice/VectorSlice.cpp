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

#include <stdexcept>

#include "VectorSlice.hpp"

template<typename T>
VectorSlice<T>::VectorSlice(const std::vector<T> *source, int begin, int end)
    : vector(source), v_begin(begin), v_end(end) 
{
    if (source == nullptr)
        throw std::invalid_argument("source is null.");
    
    if (source->size() < begin || source->size < end || begin < 0 || end < 0 || begin > end)
        throw std::out_of_range("begin/end is is out of range");
}

template<typename T>
const std::vector<T> *VectorSlice<T>::getVector() const {
    return this->vector;
}

template<typename T>
std::size_t VectorSlice<T>::size() const {
    return v_end - v_begin;
}

template<typename T>
const T &VectorSlice<T>::operator[](int id) const {
    return this->vector[v_begin + id];
}

template<typename T>
typename VectorSlice<T>::iterator VectorSlice<T>::begin() const {
    return this->vector->begin() + v_begin;
}

template<typename T>
typename VectorSlice<T>::iterator VectorSlice<T>::end() const {
    return this->vector->begin() + v_end;
}
