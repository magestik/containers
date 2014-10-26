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
