////////////////////////////////////////////////////////////////////// 
/// @file bst.hpp 
/// @author Maximilian Schroeder
/// @brief Implementation for the header file bst.h
//////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn Bst ()
/// @brief Constructs an object of type Bst with size 0
/// @pre (none)
/// @post (none)
/// @return void 
////////////////////////////////////////////////////////////////////// 
Bst<generic>::Bst () : BT<generic> ()
{
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn ~Bst ()
/// @brief Destructor for the Bst class
/// @pre (none)
/// @post (none)
/// @return void 
//////////////////////////////////////////////////////////////////////
Bst<generic>::~Bst ()
{
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn insert (generic x) 
/// @brief Inserts object of type generic into the binary search tree
/// @pre x is of a valid type
/// @post (none)
/// @param x object to be inserted into the binary search tree
/// @return void 
//////////////////////////////////////////////////////////////////////
void Bst<generic>::insert (generic x)
{
	Btn<generic> * temp;
	if(BT<generic>::empty() == true)
	{
		temp = new Btn<generic>;
		temp -> l = NULL;
		temp -> r = NULL;
		temp -> p = NULL;
		temp -> data = new generic(x);
		BT<generic>::m_root = temp;
		BT<generic>::m_size++;
	}
	else
	{
		Btn<generic> * temp1;
		temp1 = BT<generic>::m_root;
		while(temp1 != NULL)
		{
			temp = temp1;
			if(x < *(temp1 -> data))
			{
				temp1 = temp1 -> l;
			}
			else if(x > *(temp1 -> data))
			{
				temp1 = temp1 -> r;
			}
			else
			{
				throw Exception
				(
					ITEM_EXIST,
					"This item already exists in the binary search tree. Duplicates cannot be inserted."
				 );
			}
		}
		temp1 = new Btn<generic>;
		temp1 -> l = NULL;
		temp1 -> r = NULL;
		temp1 -> p = NULL;
		temp1 -> data = new generic(x);
		if(*(temp -> data) > x)
		{
			temp -> l = temp1;
		}
		else if(*(temp -> data) < x)
		{
			temp -> r = temp1;
		}
		temp1 -> p = temp;
		BT<generic>::m_size++;
	}	
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn remove (generic x) 
/// @brief Removes the object of type generic with value equal to x
/// from the binary search tree
/// @pre x is of a valid type, x exists in the binary tree
/// @post (none)
/// @param x object to be removed from the binary search tree
/// @return void 
//////////////////////////////////////////////////////////////////////
void Bst<generic>::remove (generic x)
{	
	Btn<generic> * temp;
	temp = p_search(x);
	generic * tempData;		
	if((temp -> l) == NULL && (temp -> r) == NULL) //<-- Node is a LEAF
	{		
		if(temp == BT<generic>::m_root) //<-- Node is at ROOT
		{
			delete temp -> data;
			delete temp;
			BT<generic>::m_root = NULL;
			return;
		}
		else //<-- Node is NOT at ROOT
		{
			if(*(temp -> p -> data) > *(temp -> data))
			{
				temp -> p -> l = NULL;
			}
			else if(*(temp -> p -> data) < *(temp -> data))
			{
				temp -> p -> r = NULL;
			}
			delete temp -> data;
			delete temp;
			BT<generic>::m_size--;
			return;
		}
	}
	else //<-- Node is NOT a LEAF
	{
		Btn<generic> * temp2;
		temp2 = temp;
		if((temp2 -> l) != NULL) //<-- Go Left-Rightmost
		{
			temp2 = temp2 -> l;
			while((temp2 -> r) != NULL)
			{
				temp2 = temp2 -> r;
			}
			tempData = temp2 -> data;
			temp2 -> data = temp -> data;
			temp -> data = tempData;
			if((temp2 -> l) == NULL && (temp2 -> r) ==  NULL) //<-- Node is a LEAF
			{		
				if((temp2 -> p -> l) != NULL)
				{
					if(*(temp2 -> p -> l -> data) == *(temp2 -> data))
					{					
						temp2 -> p -> l = NULL;
					}
				}								
				if((temp2 -> p -> r) != NULL)
				{						
					if(*(temp2 -> p -> r -> data) == *(temp2 -> data))
					{
						temp2 -> p -> r = NULL;
					}
				}
				delete temp2 -> data;
				delete temp2;
				BT<generic>::m_size--;
				return;
			}
			else //<-- Node is not a LEAF
			{
				remove(x);
			}
		}
		else //<-- Go Right-Leftmost
		{
			temp2 = temp2 -> r;
			while((temp2 -> l) != NULL)
			{
				temp2 = temp2 -> l;
			}
			tempData = temp2 -> data;
			temp2 -> data = temp -> data;
			temp -> data = tempData;		
			if((temp2 -> l) == NULL && (temp2 -> r) ==  NULL) //<-- Node is a LEAF
			{		
				if((temp2 -> p -> l) != NULL)
				{
					if(*(temp2 -> p -> l -> data) == *(temp2 -> data))
					{					
						temp2 -> p -> l = NULL;
					}
				}								
				if((temp2 -> p -> r) != NULL)
				{						
					if(*(temp2 -> p -> r -> data) == *(temp2 -> data))
					{
						temp2 -> p -> r = NULL;
					}
				}
				delete temp2 -> data;
				delete temp2;
				BT<generic>::m_size--;
				return;
			}
			else //<-- Node is not a LEAF
			{
				remove(x);
			}
		}
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn pre_search (generic x) 
/// @brief Searches for object of type generic equal to x in the 
/// binary search tree using PreOrder algorithm
/// @pre x is of a valid type, x exists in the binary tree
/// @post (none)
/// @param x object to be searched for the binary search tree
/// @return Pointer to node containing data equal to x 
//////////////////////////////////////////////////////////////////////
BTPreorderIterator<generic> Bst<generic>::pre_search (generic x)
{
	BTPreorderIterator<generic> i;
	for(i = (* this).pre_begin(); i != (* this).pre_end(); i++)
	{
		if((* i) == x)
		{
			return i;
		}
	}
	i = (* this).pre_end();
	if((* i) == x)
	{
		return i;
	}
	else
	{
		throw Exception
		(
			ITEM_NOT_EXIST,
			"Item does not exists within the binary search tree."
		);
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn in_search (generic x) 
/// @brief Searches for object of type generic equal to x in the 
/// binary search tree using InOrder algorithm
/// @pre x is of a valid type, x exists in the binary tree
/// @post (none)
/// @param x object to be searched for the binary search tree
/// @return Pointer to node containing data equal to x
//////////////////////////////////////////////////////////////////////
BTInorderIterator<generic> Bst<generic>::in_search (generic x)
{
	BTInorderIterator<generic> i;
	for(i = (* this).in_begin(); i != (* this).in_end(); i++)
	{		
		if((* i) == x)
		{
			return i;
		}
	}
	i = (* this).in_end();
	if((* i) == x)
	{
		return i;
	}
	else
	{
		throw Exception
		(
			ITEM_NOT_EXIST,
			"Item does not exists within the binary search tree."
		);
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn post_search (generic x) 
/// @brief Searches for object of type generic equal to x in the 
/// binary search tree using PostOrder algorithm
/// @pre x is of a valid type, x exists in the binary tree
/// @post (none)
/// @param x object to be searched for the binary search tree
/// @return Pointer to node containing data equal to x
//////////////////////////////////////////////////////////////////////
BTPostorderIterator<generic> Bst<generic>::post_search (generic x)
{
	BTPostorderIterator<generic> i;
	for(i = (* this).post_begin(); i != (* this).post_end(); i++)
	{
		if((* i) == x)
		{
			return i;
		}
	}
	i = (* this).post_end();
	if((* i) == x)
	{
		return i;
	}
	else
	{
		throw Exception
		(
			ITEM_NOT_EXIST,
			"Item does not exists within the binary search tree."
		);
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn p_insert (generic x) 
/// @brief Inserts an object of type generic equal to x into the 
/// binary search tree and returns a pointer to that node's parent
/// @pre x is of a valid type
/// @post (none)
/// @param x object to be inserted into the binary search tree
/// @return Pointer that points to inserted node's parent
//////////////////////////////////////////////////////////////////////
Btn<generic>* Bst<generic>::p_insert (generic x)
{
	Btn<generic> * temp;
	if(BT<generic>::empty() == true)
	{
		temp = new Btn<generic>;
		temp -> l = NULL;
		temp -> r = NULL;
		temp -> p = NULL;
		temp -> data = new generic(x);
		BT<generic>::m_root = temp;
		BT<generic>::m_size++;
	}
	else
	{
		Btn<generic> * temp1;
		temp1 = BT<generic>::m_root;
		while(temp1 != NULL)
		{
			temp = temp1;
			if(x < *(temp1 -> data))
			{
				temp1 = temp1 -> l;
			}
			else if(x > *(temp1 -> data))
			{
				temp1 = temp1 -> r;
			}
			else
			{
				throw Exception
				(
					ITEM_EXIST,
					"This item already exists in the binary search tree. Duplicates cannot be inserted."
				 );
			}
		}
		temp1 = new Btn<generic>;
		temp1 -> l = NULL;
		temp1 -> r = NULL;
		temp1 -> p = NULL;
		temp1 -> data = new generic(x);
		if(*(temp -> data) > x)
		{
			temp -> l = temp1;
		}
		else if(*(temp -> data) < x)
		{
			temp -> r = temp1;
		}
		temp1 -> p = temp;
		BT<generic>::m_size++;
		return temp1 -> p;
	}
	return temp -> p;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn p_remove (generic x) 
/// @brief Removes an object of type generic equal to x from the 
/// binary search tree and returns a pointer to that node's parent
/// @pre x is of a valid type, x exists within the tree
/// @post (none)
/// @param x object to be removed into the binary search tree
/// @return Pointer that points to removed node's parent
//////////////////////////////////////////////////////////////////////
Btn<generic>* Bst<generic>::p_remove (generic x)
{
	Btn<generic> * temp;
	Btn<generic> * parent;
	temp = p_search(x);
	generic * tempData;		
	if((temp -> l) == NULL && (temp -> r) == NULL) //<-- Node is a LEAF
	{		
		if(temp == BT<generic>::m_root) //<-- Node is at ROOT
		{
			parent = temp -> p;
			delete temp -> data;
			delete temp;
			BT<generic>::m_root = NULL;
			BT<generic>::m_size--;
			return parent;
		}
		else //<-- Node is NOT at ROOT
		{
			parent = temp -> p;
			if(*(temp -> p -> data) > *(temp -> data))
			{
				temp -> p -> l = NULL;
			}
			else if(*(temp -> p -> data) < *(temp -> data))
			{
				temp -> p -> r = NULL;
			}			
			delete temp -> data;
			delete temp;
			BT<generic>::m_size--;
			return parent;
		}
	}
	else //<-- Node is NOT a LEAF
	{
		Btn<generic> * temp2;
		temp2 = temp;
		if((temp2 -> l) != NULL) //<-- Go Left-Rightmost
		{
			temp2 = temp2 -> l;				
			while((temp2 -> r) != NULL)
			{
				temp2 = temp2 -> r;
			}
			tempData = temp2 -> data;
			temp2 -> data = temp -> data;
			temp -> data = tempData;
			if((temp2 -> l) == NULL && (temp2 -> r) ==  NULL) //<-- Node is a LEAF
			{		
				parent = temp2 -> p;
				if((temp2 -> p -> l) != NULL)
				{
					if(*(temp2 -> p -> l -> data) == *(temp2 -> data))
					{					
						temp2 -> p -> l = NULL;
					}
				}								
				if((temp2 -> p -> r) != NULL)
				{						
					if(*(temp2 -> p -> r -> data) == *(temp2 -> data))
					{
						temp2 -> p -> r = NULL;
					}
				}				
				delete temp2 -> data;
				delete temp2;
				BT<generic>::m_size--;
				return parent;
			}
			else //<-- Node is not a LEAF
			{
				return p_remove(x);
			}
		}
		else //<-- Go Right-Leftmost
		{
			temp2 = temp2 -> r;
			while((temp2 -> l) != NULL)
			{
				temp2 = temp2 -> l;
			}
			tempData = temp2 -> data;
			temp2 -> data = temp -> data;
			temp -> data = tempData;		
			if((temp2 -> l) == NULL && (temp2 -> r) ==  NULL) //<-- Node is a LEAF
			{		
				parent = temp2 -> p;
				if((temp2 -> p -> l) != NULL)
				{
					if(*(temp2 -> p -> l -> data) == *(temp2 -> data))
					{					
						temp2 -> p -> l = NULL;
					}
				}								
				if((temp2 -> p -> r) != NULL)
				{						
					if(*(temp2 -> p -> r -> data) == *(temp2 -> data))
					{
						temp2 -> p -> r = NULL;
					}
				}
				delete temp2 -> data;
				delete temp2;
				BT<generic>::m_size--;
				return parent;
			}
			else //<-- Node is not a LEAF
			{
				return p_remove(x);
			}
		}
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn p_search (generic x) 
/// @brief Searches for an object of type generic equal to x in the 
/// binary search tree and returns a pointer to that node
/// @pre x is of a valid type, x exists within the tree
/// @post (none)
/// @param x object to be searched for in the binary search tree
/// @return Pointer that points to found node
//////////////////////////////////////////////////////////////////////
Btn<generic>* Bst<generic>::p_search (generic x)
{
	return in_search(x).current();
}
