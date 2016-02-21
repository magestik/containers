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

#pragma once

#ifndef ASSERT
#	define ASSERT(exp, msg)
#endif // ASSERT

/**
 * Default constructor
 */
template<typename T>
inline List<T>::List(void) : m_pFirst(nullptr), m_pLast(nullptr), m_count(0)
{
	// ...
}

/**
 * Copy constructor
 */
template<typename T>
inline List<T>::List(const List<T> & list) : m_pFirst(nullptr), m_pLast(nullptr), m_count(0)
{
	m_count = _copyList(list, &m_pFirst, &m_pLast);
}

/**
 * Destructor
 */
template<typename T>
inline List<T>::~List(void)
{
	clear();
}

/**
 * Assignement operator
 */
template<typename T>
List<T> & List<T>::operator = (const List<T> & list)
{
	clear();
	m_count = _copyList(list, &m_pFirst, &m_pLast);
	return(*this);
}

/**
 * Add Head
 */
template<typename T>
inline void List<T>::insertAtHead(const T & elmt)
{
	if (0 == m_count)
	{
		_addFirst(elmt);
		return;
	}

	sNode * pNode = new sNode(elmt);
	pNode->next = m_pFirst; // create link to next element
	m_pFirst = pNode;

	++m_count;
}

/**
 * Add Tail
 */
template<typename T>
inline void List<T>::insertAtTail(const T & elmt)
{
	if (0 == m_count)
	{
		_addFirst(elmt);
		return;
	}

	sNode * pNode = new sNode(elmt);
	m_pLast->next = pNode; // create link from previous element
	m_pLast = pNode;

	++m_count;
}

/**
 * Add an element at choosen position
 * Call "addHead" when index == 0   because we need to update m_pFirst
 * Call "addTail" when index == end because we need to update m_pLast
 */
template<typename T>
inline void List<T>::insertAtIndex(const T & elmt, unsigned int index)
{
	ASSERT(m_count >= index, "index out of bounds");

	if (0 == m_count)
	{
		_addFirst(elmt);
		return;
	}

	if (0 == index)
	{
		insertAtHead(elmt);
		return;
	}

	if (m_count == (index + 1))
	{
		insertAtTail(elmt);
		return;
	}

	sNode * pPreviousNode = _access(index - 1);

	sNode * pNode = new sNode(elmt);

	pNode->next = pPreviousNode->next; // create link to next element
	pPreviousNode->next = pNode; // create link from previous element

	++m_count;
}

/**
 * Remove Head element
 */
template<typename T>
inline void List<T>::removeFromHead(void)
{
	ASSERT(m_count > 0, "the list is already empty");

	if (1 == m_count)
	{
		_removeLast();
		return;
	}

	sNode * pNodeToDelete = m_pFirst;
	m_pFirst = pNodeToDelete->next;
	delete pNodeToDelete;

	--m_count;
}

/**
 * Remove Tail element
 */
template<typename T>
inline void List<T>::removeFromTail(void)
{
	ASSERT(m_count > 0, "the list is already empty");

	if (1 == m_count)
	{
		_removeLast();
		return;
	}

	sNode * pNodeToDelete = m_pLast;
	m_pLast = _access(m_count - 2); // get last-but-one element
	m_pLast->next = nullptr;
	delete pNodeToDelete;

	--m_count;
}

/**
 * Remove any element in the list
 * Call "removeHead" when index == 0   because we need to update m_pFirst
 * Call "removeTail" when index == end because we need to update m_pLast
 */
template<typename T>
inline void List<T>::removeFromIndex(unsigned int index)
{
	ASSERT(m_count > index, "the list is already empty");

	if (1 == m_count)
	{
		_removeLast();
		return;
	}

	if (0 == index)
	{
		removeFromHead();
		return;
	}

	if (m_count == (index + 1))
	{
		removeFromTail();
		return;
	}

	sNode * pPreviousNode = _access(index - 1);

	sNode * pNodeToDelete = pPreviousNode->next;
	pPreviousNode->next = pNodeToDelete->next;
	delete pNodeToDelete;

	--m_count;
}

/**
 * Remove all elements in the list
 */
template<typename T>
inline void List<T>::clear(void)
{
	while (!empty())
	{
		removeFromHead();
	}
}

/**
 * Add all elements of a List in Head
 */
template<typename T>
inline void List<T>::appendToHead(const List<T> & list)
{
	if (list.m_count > 0)
	{
		sNode * pFirstNode	= nullptr;
		sNode * pLastNode	= nullptr;

		m_count += _copyList(list, &pFirstNode, &pLastNode);

		pLastNode->next = m_pFirst; // make the link

		m_pFirst = pFirstNode; // set the new "first"
	}
}

/**
 * Add all elements of a List in Tail
 */
template<typename T>
inline void List<T>::appendToTail(const List<T> & list)
{
	if (list.m_count > 0)
	{
		sNode * pFirstNode	= nullptr;
		sNode * pLastNode	= nullptr;

		m_count += _copyList(list, &pFirstNode, &pLastNode);

		m_pLast->next = pFirstNode; // make the link

		m_pLast = pLastNode; // set the new "last"
	}
}

/**
 * Test whether list is empty
 */
template<typename T>
inline bool List<T>::empty(void) const
{
	return(0 == m_count);
}

/**
 * Return the number of element in the list
 */
template<typename T>
inline unsigned int List<T>::count(void) const
{
	return(m_count);
}

/**
 * Acces first element
 */
template<typename T>
inline T & List<T>::head(void)
{
	return(m_pFirst->data);
}

/**
 * Acces first element
 */
template<typename T>
inline const T & List<T>::head(void) const
{
	return(m_pFirst->data);
}

/**
 * Acces last element
 */
template<typename T>
inline T & List<T>::tail(void)
{
	return(m_pLast->data);
}

/**
 * Acces last element
 */
template<typename T>
inline const T & List<T>::tail(void) const
{
	return(m_pLast->data);
}

/**
 * Acces any element in the list
 * Not optimized to loop through the list !
 */
template<typename T>
inline T & List<T>::operator [] (unsigned int index)
{
	ASSERT(m_count > index, "index out of bounds");

	sNode * pNode = _access(index);

	return(pNode->data);
}

/**
 * Acces any element in the list
 * Not optimized to loop through the list !
 */
template<typename T>
inline const T & List<T>::operator [] (unsigned int index) const
{
	ASSERT(m_count > index, "index out of bounds");

	sNode * pNode = _access(index);

	return(pNode->data);
}

/**
 * Access any Node
 */
template<typename T>
inline typename List<T>::sNode * List<T>::_access(unsigned int index) const
{
	sNode * pNode = m_pFirst;

	while (0 != index)
	{
		pNode = pNode->next;
		--index;
	}

	return(pNode);
}

/**
 * Optimized function to add the first element (when count = 0)
 */
template<typename T>
inline void List<T>::_addFirst(const T & elmt)
{
	ASSERT(0 == m_count, "the list is not empty");

	sNode * pNode = new sNode(elmt);

	m_pFirst = pNode;
	m_pLast	 = pNode;

	m_count  = 1;
}

/**
 * Optimized function to remove the last element (when count = 1)
 */
template<typename T>
inline void List<T>::_removeLast(void)
{
	ASSERT(1 == m_count, "the list has more than one element");

	delete m_pFirst;

	m_pFirst = nullptr;
	m_pLast	 = nullptr;

	m_count  = 0;
}

/**
 * Copy list and return pointer to the copy of the first and last element
 */
template<typename T>
inline unsigned int List<T>::_copyList(const List<T> & list, sNode ** pFirst, sNode ** pLast)
{
	ASSERT(0 < list.m_count, "the list is empty");

	sNode * pSourceNode = list.m_pFirst;

	*pFirst = new sNode(pSourceNode->data);
	*pLast = *pFirst;

	pSourceNode = pSourceNode->next;

	for (int i = 1; i < list.m_count; ++i)
	{
		// allocate new node
		sNode * pNode = new sNode(pSourceNode->data);

		// set the "next" member of the last allocated node
		(*pLast)->next = pNode;

		// set pLast to the newly allocated node
		*pLast = pNode;

		// iterate to the next element of the list to be copied
		pSourceNode = pSourceNode->next;
	}

	return(list.m_count);
}
