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

/**
 * @brief Vector slice is a class that provides slicing functionality for vectors.
 * 
 * It generates iterator between 2 points of the vector that allows getting elements between points.
 * 
 * @tparam T Type parameter of a vector.
 * @tparam std::allocator<T> Allocator parameter of a base vector.
 */
template<typename T, typename Allocator = std::allocator<T>>
class VectorSlice final
{
private:
    const std::vector<T, Allocator> *vector;
    const int v_begin, v_end;

public:
    /**
     * @brief A type that provides a random-access iterator that can read a const element in a slice.
     * 
     * @remark A type VectorSlice::iterator cannot be used to modify the value of an element.
     */
    using iterator = typename std::vector<T, Allocator>::const_iterator;

    /**
     * @brief Slices vector on [begin; end].
     * 
     * @param source pointer to a vector.
     * @param begin start index in the vector.
     * @param end last element
     * 
     * @throw std::invalid_argument if the `*source` is `nullptr`.
     * @throw std::range_error if the range for an empty vector isn't `(0, 0)`.
     * @throw std::range_error if the `begin` isn't on `[0; size of vector)`.
     * @throw std::range_error if the `end` isn't on `(0; size of vecor]`.
     */
    VectorSlice(const std::vector<T, Allocator> *source, int begin, int end);

    /**
     * @brief Get the base vector.
     */
    const std::vector<T, Allocator> *getVector() const;

    /**
     * @brief Compute the size of the slice.
     * 
     * @return std::size_t distance between begin and end.
     */
    std::size_t size() const;
    
    /**
     * @brief Returns a reference to the element at specified location pos. No bounds checking is performed.
     * 
     * @param id index of the element to return.
     * @return const T& const reference to the requested element.
     */
    const T &operator[] (int id) const;

    /**
     * @brief Returns an iterator to the first element of the slice.
     */
    iterator begin() const;

    /**
     * @brief Returns an iterator to the element following the last element of the slice. 
     * 
     * Used as a placeholder to show the end-point of the slice.
     * 
     * @return iterator Iterator to the element following the last element. 
     */
    iterator end() const;
};

// REALIZATION

template<typename T, typename Allocator>
VectorSlice<T, Allocator>::VectorSlice(const std::vector<T, Allocator> *source, int begin, int end)
    : vector(source), v_begin(begin), v_end(end) 
{
    if (source == nullptr)
        throw std::invalid_argument("source is null.");

    if (source->size() == 0)
    {
        if (begin != 0 || end != 0)
            throw std::range_error("for empty slices with empty vector use begin = 0 and end = 0.");
    }
    else
    {
        if (begin >= end)
            throw std::range_error("begin must be bigger than end (begin < end).");
        if (begin >= source->size() || begin < 0)
            throw std::range_error("begin isn't on range [0; size).");
        if (end > source->size() || end < 0)
            throw std::range_error("end isn't on range (0; size]");
    }
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
