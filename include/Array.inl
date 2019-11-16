#pragma once

#ifndef ASSERT
#	define ASSERT(exp, msg)
#endif // ASSERT

/**
 * Default constructor
 */
template<typename T, class Allocator>
inline Array<T, Allocator>::Array(void) : m_allocator(), m_pData(nullptr), m_count(0)
{
	// ...
}

/**
 * Pointer-copy constructor
 */
template<typename T, class Allocator>
inline Array<T, Allocator>::Array(T * data, unsigned int size) : m_allocator(data, size), m_pData(nullptr), m_count(size)
{
	ASSERT(nullptr != data, "data is null");
}

/**
 * Destructor
 */
template<typename T, class Allocator>
inline Array<T, Allocator>::~Array(void)
{
	clear();
}

/**
 * Add an element at the end
 */
template<typename T, class Allocator>
inline void Array<T, Allocator>::add(const T & elmt)
{
	unsigned int count = m_count++;
	m_pData = (T*)m_allocator.resize(m_pData, m_count * sizeof(T));
	ASSERT(m_pData != nullptr, "allocation failed");
	m_pData[count] = elmt;
}

template<typename T, class Allocator>
inline void Array<T, Allocator>::removeFirstElement(void)
{
	removeElementAtIndex(0u);
}

template<typename T, class Allocator>
inline void Array<T, Allocator>::removeLastElement(void)
{
	removeElementAtIndex(m_count);
}

/**
 * Remove element located at index
 */
template<typename T, class Allocator>
inline void Array<T, Allocator>::removeElementAtIndex(unsigned int n)
{
	ASSERT(m_count > 0u, "the array is empty");
	ASSERT(n < m_count, "index out of bounds");
	--m_count;
	for (unsigned int i = n; i < m_count; ++i)
	{
		m_pData[i] = m_pData[i+1];
	}
	m_pData = (T*)m_allocator.resize(m_pData, m_count * sizeof(T));
	ASSERT(m_pData != nullptr, "allocation failed");
}

/**
 * Access any element
 */
template<typename T, class Allocator>
inline const T & Array<T, Allocator>::operator [] (unsigned int n) const
{
	ASSERT(n < m_count, "index out of bounds");
	return(m_pData[n]);
}

/**
 * Access any element
 */
template<typename T, class Allocator>
inline T & Array<T, Allocator>::operator [] (unsigned int n)
{
	ASSERT(n < m_count, "index out of bounds");
	return(m_pData[n]);
}

/**
 * Test whether the container is empty
 */
template<typename T, class Allocator>
inline bool Array<T, Allocator>::empty(void) const
{
	return(0u == m_count);
}

/**
 * Return the number of element
 */
template<typename T, class Allocator>
inline unsigned int Array<T, Allocator>::count(void) const
{
	return(m_count);
}

/**
 * Remove all elements
 */
template<typename T, class Allocator>
inline void Array<T, Allocator>::clear(void)
{
	m_count = 0u;
	m_allocator.release(m_pData);
	m_pData = nullptr;
}
