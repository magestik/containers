/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.
 */

#ifndef ASSERT
#define ASSERT(exp)
#endif // ASSERT

#include <stdlib.h> // for malloc/free & realloc

/**
 * Default constructor
 */
template<typename T>
inline Array<T>::Array(void) : m_pData(nullptr), m_count(0), m_size(0)
{
    /* ... */
}

/**
 * Pointer-copy constructor
 */
template<typename T>
inline Array<T>::Array(T * data, unsigned int size) : m_pData(data), m_count(size), m_size(size)
{
    ASSERT(nullptr != data);
}

/**
 * Destructor
 */
template<typename T>
inline Array<T>::~Array(void)
{
    free(m_pData);
}

/**
 * Add an element on the top
 */
template<typename T>
inline void Array<T>::add(const T & elmt)
{
    if (m_count >= m_size)
    {
        reserve((m_size + 1) * 2);
    }

    m_pData[m_count++] = elmt;
}


/**
 * Access any element
 */
template<typename T>
inline const T & Array<T>::operator [] (unsigned int n) const
{
    ASSERT(n < m_size);
    return(m_pData[n]);
}

/**
 * Access any element
 */
template<typename T>
inline T & Array<T>::operator [] (unsigned int n)
{
    ASSERT(n < m_size);
    return(m_pData[n]);
}

/**
 * Test whether the container is empty
 */
template<typename T>
inline bool Array<T>::empty(void) const
{
    return(0 == m_count);
}

/**
 * Return the number of element
 */
template<typename T>
inline unsigned int Array<T>::count(void) const
{
    return(m_count);
}

/**
 * Remove all elements
 */
template<typename T>
inline void Array<T>::clear(void)
{
    m_count = 0;
    m_size = 0;
    free(m_pData);
    m_pData = nullptr;
}

/**
 * Preallocate memory
 */
template<typename T>
inline void Array<T>::reserve(unsigned int count)
{
    if (count > m_size)
    {
        m_size = count;
        m_pData = (T *)realloc(m_pData, count * sizeof(T));
        ASSERT(nullptr != m_pData);
    }
}

