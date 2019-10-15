#pragma once

template<typename T, class Allocator>
class Array
{

public:

	typedef T type;

	struct iterator
	{
		explicit        iterator        (T * first) : current(first) { /* ... */ }
		T &				operator *		(void) { return *current; }
		iterator		operator ++		(void) { return iterator(current++); }
		bool			operator !=		(const iterator & it) { return(current != it.current); }

	private:
		T * current;
	};

	// Constructors / Destructor
				Array   (void);
	explicit    Array   (T * data, unsigned int size);
				~Array  (void);

	// Add methods
	void            add						(const T & elmt);

	// Remove methods
	void            removeFirstElement		(void);
	void            removeLastElement		(void);
	void            removeElementAtIndex	(unsigned int index);

	void            clear					(void);

	// Element accessors
	T &				operator []				(unsigned int index);
	const T &		operator []				(unsigned int index) const;

	// Size accessors
	bool			empty					(void) const;
	unsigned int	count					(void) const;

	// Iterators access
	iterator		begin					(void) { return iterator(m_pData); }
	iterator		end						(void) { return iterator(m_pData+m_count); }

private:

	Allocator		m_allocator;
	T *				m_pData;	// continuous memory block
	unsigned int	m_count;	// number of element

};

#include "Array.inl"
