#pragma once

template <typename T>
class BinarySearchTree
{

	struct sNode
	{
		sNode(const T & d) : data(d), left(nullptr), right(nullptr) { /* ... */ }

		T data;
		sNode * left;
		sNode * right;
	};

public:


	// Constructors / Destructor
	BinarySearchTree(void);
	~BinarySearchTree(void);

	// Add/Remove methods
	bool insert(const T & p);

	// Size accessors
	bool empty(void);

private:

	bool _insert(sNode ** node, const T & p);
	bool _remove(sNode * node);

private:

	sNode * m_pRoot;

};

#include "BinarySearchTree.inl"
