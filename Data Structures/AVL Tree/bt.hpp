////////////////////////////////////////////////////////////////////// 
/// @file bt.hpp 
/// @author Maximilian Schroeder
/// @brief Implementation of header file bt.h
//////////////////////////////////////////////////////////////////////
#include<iostream>
#include<string>
using namespace std;

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn BT () 
/// @brief Constructs an object of type BT of size 0
/// @pre (none)
/// @post m_size = 0, m_root = NULL
/// @return void 
////////////////////////////////////////////////////////////////////// 
BT<generic>::BT()
{
	m_root = NULL;
	m_size = 0;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn ~BT () 
/// @brief Destructor for BT class
/// @pre (none)
/// @post (none)
/// @return void 
//////////////////////////////////////////////////////////////////////
BT<generic>::~BT()
{
	clear();
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn BT (BT & x) 
/// @brief Constructs an object of type BT that is a duplicate of x in 
/// terms of size and contents
/// @pre x is a valid BT
/// @post m_size = x.size()
/// @param x BT to be copied onto target BT
/// @return void 
//////////////////////////////////////////////////////////////////////
BT<generic>::BT(BT & x)
{
	(* this) = x;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator= (const BT & x) 
/// @brief Constructs an object of type BT that is a duplicate of x in 
/// terms of size and contents
/// @pre x is a valid BT
/// @post m_size = x.size()
/// @param x BT to be copied onto target BT
/// @return copy of BT on right side of operator
////////////////////////////////////////////////////////////////////// 
BT<generic>& BT<generic>::operator= (const BT & x)
{
	PreOrder i;
	string path = "";
	Btn<generic> * temp;
	Btn<generic> * temp2;
	m_root = NULL;
	m_size = 0;
	for(i = x.pre_begin(); i != x.pre_end(); i++)
	{	
		if(empty() == true) //root of BT
		{
			temp = new Btn<generic>;
			temp -> l = NULL;
			temp -> r = NULL;
			temp -> p = NULL;
			temp -> data = new generic(* i);
			m_root = temp;
			m_size++;
		}
		else
		{
			temp2 = i.current();
			while(temp2 -> p != NULL)
			{
				if(temp2 -> p -> l == temp2)
				{
					path += "l";
					temp2 = temp2 -> p;
				}
				else if(temp2 -> p -> r == temp2)
				{
					path += "r";
					temp2 = temp2 -> p;
				}
			}
			temp2 = i.current();
			temp = m_root;
			for(int j = (path.length() - 1); j > 0 ; j--)
			{
				if(path[j] == 'l')
				{
					temp = temp -> l;
				}
				else if(path[j] == 'r')
				{
					temp = temp -> r;
				}
			}
			if(temp2 -> p -> l == temp2) //left-child of parent
			{
				temp2 = NULL;
				temp2 = new Btn<generic>;
				temp2 -> l = NULL;
				temp2 -> r = NULL;
				temp2 -> p = temp;
				temp2 -> data = new generic(* i);
				temp -> l = temp2;
				m_size++;
			}
			else if(temp2 -> p -> r == temp2) //right-child of parent
			{
				temp2 = NULL;
				temp2 = new Btn<generic>;
				temp2 -> l = NULL;
				temp2 -> r = NULL;
				temp2 -> p = temp;
				temp2 -> data = new generic(* i);
				temp -> r = temp2;
				m_size++;
			}			
		}
		path = "";
	}
	i = x.pre_end();
	temp2 = i.current();
	while(temp2 -> p != NULL)
	{
		if(temp2 -> p -> l == temp2)
		{
			path += "l";
			temp2 = temp2 -> p;
		}
		else if(temp2 -> p -> r == temp2)
		{
			path += "r";
			temp2 = temp2 -> p;
		}
	}
	temp2 = i.current();
	temp = m_root;
	for(int j = (path.length() - 1); j > 0 ; j--)
	{
		if(path[j] == 'l')
		{
			temp = temp -> l;
		}
		else if(path[j] == 'r')
		{
			temp = temp -> r;
		}
	}
	if(temp2 -> p -> l == temp2) //left-child of parent
	{
		temp2 = NULL;
		temp2 = new Btn<generic>;
		temp2 -> l = NULL;
		temp2 -> r = NULL;
		temp2 -> p = temp;
		temp2 -> data = new generic(* i);
		temp -> l = temp2;
		m_size++;
	}
	else if(temp2 -> p -> r == temp2) //right-child of parent
	{
		temp2 = NULL;
		temp2 = new Btn<generic>;
		temp2 -> l = NULL;
		temp2 -> r = NULL;
		temp2 -> p = temp;
		temp2 -> data = new generic(* i);
		temp -> r = temp2;
		m_size++;
	}
	return (* this);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn clear () 
/// @brief Deletes all values in binary search tree
/// @pre (none)
/// @post m_size = 0
/// @return void 
//////////////////////////////////////////////////////////////////////
void BT<generic>::clear ()
{
	if(empty() == true)
	{
		return;
	}
	PostOrder i;
	string path = "";
	Btn<generic> * temp;
	Btn<generic> * temp2;
	i = (* this).post_begin();
	while(i != (* this).post_end())
	{			
		temp2 = i.current();
		while(temp2 -> p != NULL)
		{
			if(temp2 -> p -> l == temp2)
			{
				path += "l";
				temp2 = temp2 -> p;
			}
			else if(temp2 -> p -> r == temp2)
			{
				path += "r";
				temp2 = temp2 -> p;
			}
		}
		temp2 = NULL;
		temp = m_root;
		for(int j = (path.length() - 1); j >= 0 ; j--)
		{
			if(path[j] == 'l')
			{
				temp = temp -> l;
			}
			else if(path[j] == 'r')
			{
				temp = temp -> r;
			}
		}
		i++;
		if(temp -> p -> l != NULL)
		{
			if(temp -> p -> l == temp) //left-child of parent
			{
				temp -> p -> l = NULL;
				delete temp -> data;
				delete temp;
				temp = NULL;
				m_size--;
			}
		}
		else if(temp -> p -> r != NULL)
		{
			if(temp -> p -> r == temp) //right-child of parent
			{
				temp -> p -> r = NULL;
				delete temp -> data;
				delete temp;
				temp = NULL;
				m_size--;
			}
		}
		path = "";
	}
	i = (* this).post_end();
	temp = m_root;
	delete temp -> data;
	delete temp;
	m_root = NULL;
	m_size--;
	temp = NULL;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn empty () 
/// @brief Returns a boolean based on whether or not the binary search
/// tree is empty
/// @pre (none)
/// @post (none)
/// @return true if tree is empty, false if otherwise 
//////////////////////////////////////////////////////////////////////
bool BT<generic>::empty ()
{
	if(m_size == 0)
	{
		return true;
	}
	return false;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn size () 
/// @brief Returns amount of items in the binary search tree
/// @pre (none)
/// @post (none)
/// @return size of the binary search tree
////////////////////////////////////////////////////////////////////// 
unsigned int BT<generic>::size ()
{
	return m_size;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn pre_begin () 
/// @brief Returns an iterator pointing to the node examined first in
/// the PreOrder algorithm
/// @pre (none)
/// @post (none)
/// @return Preorderiterator at first node to be examined
////////////////////////////////////////////////////////////////////// 
BTPreorderIterator<generic> BT<generic>::pre_begin () const
{
	return BTPreorderIterator<generic> (m_root);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn pre_end () 
/// @brief Returns an iterator pointing to the node examined last in
/// the PreOrder algorithm
/// @pre (none)
/// @post (none)
/// @return Preorderiterator at last node to be examined
////////////////////////////////////////////////////////////////////// 
BTPreorderIterator<generic> BT<generic>::pre_end () const
{
	Btn<generic> * temp;
	temp = m_root;
	while(temp -> l != NULL || temp -> r != NULL)
	{
		if(temp -> r != NULL)
		{
			temp = temp -> r;
		}
		else if(temp -> r == NULL && temp -> l != NULL)
		{
			temp = temp -> l;
		}
	}
	return BTPreorderIterator<generic> (temp);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn in_begin () 
/// @brief Returns an iterator pointing to the node examined first in
/// the InOrder algorithm
/// @pre (none)
/// @post (none)
/// @return Inorderiterator at first node to be examined
////////////////////////////////////////////////////////////////////// 
BTInorderIterator<generic> BT<generic>::in_begin () const
{
	Btn<generic> * temp;
	temp = m_root;
	while(temp -> l != NULL)
	{
		temp = temp -> l;
	}
	return BTInorderIterator<generic> (temp);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn in_end () 
/// @brief Returns an iterator pointing to the node examined last in
/// the InOrder algorithm
/// @pre (none)
/// @post (none)
/// @return Inorderiterator at last node to be examined
////////////////////////////////////////////////////////////////////// 
BTInorderIterator<generic> BT<generic>::in_end () const
{
	Btn<generic> * temp;
	temp = m_root;
	while(temp -> r != NULL)
	{
		temp = temp -> r;
	}
	return BTInorderIterator<generic> (temp);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn post_begin () 
/// @brief Returns an iterator pointing to the node examined first in
/// the PostOrder algorithm
/// @pre (none)
/// @post (none)
/// @return Postorderiterator at first node to be examined
////////////////////////////////////////////////////////////////////// 
BTPostorderIterator<generic> BT<generic>::post_begin () const
{
	Btn<generic> * temp;
	temp = m_root;
	while(temp -> l != NULL || temp -> r != NULL)
	{
		if(temp -> l != NULL)
		{
			temp = temp -> l;
		}
		else if(temp -> l == NULL && temp -> r != NULL)
		{
			temp = temp -> r;
		}
	}
	return BTPostorderIterator<generic> (temp);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn post_end () 
/// @brief Returns an iterator pointing to the node examined last in
/// the PostOrder algorithm
/// @pre (none)
/// @post (none)
/// @return Postorderiterator at last node to be examined
////////////////////////////////////////////////////////////////////// 
BTPostorderIterator<generic> BT<generic>::post_end () const
{
	return BTPostorderIterator<generic> (m_root);
}
