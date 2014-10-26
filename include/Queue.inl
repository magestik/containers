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

/**
 * Default constructor
 */
template<typename T>
inline Queue<T>::Queue(void) : m_container()
{
	/* ... */
}

/**
 * Constructor from List
 */
template<typename T>
inline Queue<T>::Queue(const List<T> & list)
{
	m_container = list;
}

/**
 * Destructor
 */
template<typename T>
inline Queue<T>::~Queue(void)
{
	m_container.clear();
}

/**
 * Assigment operator from List
 */
Queue<T> & Queue<T>::operator =	(const List<T> & list)
{
	m_container = list;
}

/**
 * Add an element at the end
 */
template<typename T>
inline void Queue<T>::enqueue(const T & elmt)
{
	m_container.insertAtTail(elmt);
}

/**
 * Remove the first element
 */
template<typename T>
inline void Queue<T>::dequeue(void)
{
	m_container.removeFromHead();
}

/**
 * Get the first element
 */
template<typename T>
inline T & Queue<T>::first(void)
{
	return(m_container.head());
}

/**
 * Get the first element
 */
template<typename T>
inline const T & Queue<T>::first(void) const
{
	return(m_container.head());
}

/**
 * Get the last element
 */
template<typename T>
inline T & Queue<T>::last(void)
{
	return(m_container.tail());
}

/**
 * Get the last element
 */
template<typename T>
inline const T & Queue<T>::last(void) const
{
	return(m_container.tail());
}

/**
 * Test whether stack is empty
 */
template<typename T>
inline bool Queue<T>::empty(void) const
{
	return(m_container.empty());
}

/**
 * Return the number of element in the stack
 */
template<typename T>
inline unsigned int Queue<T>::count(void) const
{
	return(m_container.count());
}
