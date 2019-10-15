#pragma once

#ifndef ASSERT
#	define ASSERT(exp, msg)
#endif // ASSERT

/**
 * Default constructor
 */
template<typename T>
inline BinarySearchTree<T>::BinarySearchTree(void) : m_pRoot(nullptr)
{
	// ...
}

/**
 * Destructor
 */
template<typename T>
inline BinarySearchTree<T>::~BinarySearchTree(void)
{
	_remove(m_pRoot);
}

/**
 * Test whether the tree is empty
 */
template<typename T>
inline bool BinarySearchTree<T>::empty(void)
{
	return(nullptr == m_pRoot);
}

/**
 * Insert an element in the tree
 */
template<typename T>
inline bool BinarySearchTree<T>::insert(const T & p)
{
	return(_insert(&(m_pRoot), p));
}

/**
 * Insert an element in the tree (internal)
 */
template<typename T>
inline bool BinarySearchTree<T>::_insert(sNode ** pNode, const T & p)
{
	if (nullptr == *pNode)
	{
		*pNode = new sNode(p);
		return(true);
	}
	else
	{
		int result = compare(p, (*pNode)->data);

		if (result > 0)
		{
			return(_insert(&((*pNode)->right), p));
		}
		else if (result < 0)
		{
			return(_insert(&((*pNode)->left), p));
		}
		else
		{
			return(false);
		}
	}
}

/**
 * Remove an element from the tree (internal)
 */
template<typename T>
inline bool BinarySearchTree<T>::_remove(sNode * pNode)
{
	if (nullptr != pNode)
	{
		_remove(pNode->left);
		_remove(pNode->right);
		delete pNode;
	}
}
