#pragma once

template<typename T, typename Allocator>
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
	List			(const List<T, Allocator> & list);
    ~List			(void);

	List<T, Allocator> &	operator =		(const List<T, Allocator> & list);

    // Add methods
	void					insertAtHead	(const T & elmt); // O(1)
	void					insertAtTail	(const T & elmt); // O(1)
	void					insertAtIndex	(const T & elmt, unsigned int index); // O(n/2)

    // Remove methods
	void					removeFromHead	(void); // O(1)
	void					removeFromTail	(void); // O(n)
	void					removeFromIndex	(unsigned int index); // O(n/2)

	void					clear			(void);

    // Merge methods
	void					appendToHead	(const List<T, Allocator> & list);
	void					appendToTail	(const List<T, Allocator> & list);

    // Element accessors
	T &						head			(void);
	const T &				head			(void) const;

	T &						tail			(void);
	const T &				tail			(void) const;

	T &						operator []		(unsigned int index);
	const T &				operator []		(unsigned int index) const;

    // Size accessors
	bool					empty			(void) const;
	unsigned int			count			(void) const;

    // Iterators access
	iterator				begin			(void) { return iterator(m_pFirst); }
	iterator				end				(void) { return iterator(nullptr); }

private:

	sNode *					_access			(unsigned int index) const;
	void					_addFirst		(const T & elmt);
	void					_removeLast		(void);
	unsigned int			_copyList		(const List<T, Allocator> & list, sNode ** pFirst, sNode ** pLast);

private:

	Allocator		m_allocator;
    sNode *			m_pFirst;		// first element
    sNode *			m_pLast;		// last element (for quick tail insertion)
    unsigned int	m_count;		// number of element in the list (for quick empty check)

};

#include "List.inl"
