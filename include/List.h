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

template<typename T>
class List
{

    struct sNode
    {
        sNode(const T & d) : data(d), next(nullptr) { /* ... */ }

        T data;
        sNode * next;
    };

public:

    typedef T type;

    struct iterator
    {
        explicit        iterator        (sNode * pNode) : current(pNode) { /* ... */ }
        T &				operator *		(void) { return current->data; }
        iterator		operator ++		(void) { iterator it(current); current = current->next; return(it); }
        bool			operator !=		(const iterator & it) { return(current != it.current); }

    private:
        sNode * current;
    };

    // Constructors / Destructor
    List			(void);
    List			(const List<T> & list);
    ~List			(void);

    List<T> &		operator =		(const List<T> & list);

    // Add methods
    void			insertAtHead	(const T & elmt); // O(1)
    void			insertAtTail	(const T & elmt); // O(1)
    void			insertAtIndex	(const T & elmt, unsigned int index); // O(n/2)

    // Remove methods
    void			removeFromHead	(void); // O(1)
    void			removeFromTail	(void); // O(n)
    void			removeFromIndex	(unsigned int index); // O(n/2)

    void			clear			(void);

    // Merge methods
    void			appendToHead	(const List<T> & list);
    void			appendToTail	(const List<T> & list);

    // Element accessors
    T &				head			(void);
    const T &		head			(void) const;

    T &				tail			(void);
    const T &		tail			(void) const;

    T &				operator []		(unsigned int index);
    const T &		operator []		(unsigned int index) const;

    // Size accessors
    bool			empty			(void) const;
    unsigned int	count			(void) const;

    // Iterators access
    iterator		begin			(void) { return iterator(m_pFirst); }
    iterator		end				(void) { return iterator(nullptr); }

private:

    sNode *			_access			(unsigned int index) const;
    void			_addFirst		(const T & elmt);
    void			_removeLast		(void);
    unsigned int	_copyList		(const List<T> & list, sNode ** pFirst, sNode ** pLast);

private:

    sNode *			m_pFirst;		// first element
    sNode *			m_pLast;		// last element (for quick tail insertion)
    unsigned int	m_count;		// number of element in the list (for quick empty check)

};

#include "List.inl"
