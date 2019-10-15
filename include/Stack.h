#pragma once

template<typename T, class Allocator>
class Stack
{

public:

	typedef T type;

	// Constructors / Destructor
				Stack		(void);
	explicit	Stack		(T * data, unsigned int size);
				~Stack		(void);

	// Add methods
	void		push		(const T & elmt);

	// Remove methods
	void		pop			(void);

	// Element accessors
	const T &	top			(void) const;
	T &			top			(void);

	// Remove methods
	void            clear   (void);

	// Size accessors
	bool			empty	(void) const;
	unsigned int	count	(void) const;

private:

	Allocator		m_allocator;
	T *				m_pData;	// continuous memory block
	unsigned int	m_count;	// number of element

};

#include "Stack.inl"
