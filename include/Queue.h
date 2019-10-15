#pragma once

#include "List.h"

template<typename T>
class Queue
{

public:

	typedef T type;

	// Constructors / Destructor
	inline				Queue		(void);
	inline				Queue		(const List<T> & list);
	inline				~Queue		(void);

	Queue<T> &			operator =		(const List<T> & list);

	// Add/Remove methods
	inline void			enqueue		(const T & elmt);
	inline void			dequeue		(void);

	inline void			clear		(void);

	// Element accessors
	inline T &			first		(void);
	inline const T &	first		(void) const;

	inline T &			last		(void);
	inline const T &	last		(void) const;

	// Size accessors
	inline bool				empty	(void) const;
	inline unsigned int		count	(void) const;

private:

	List<T> m_container;

};

#include "Queue.inl"
