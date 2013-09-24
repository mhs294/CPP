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
Bst<generic>::Bst ()
{
	m_root = NULL;
	m_size = 0;
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
	clear();
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
	if(empty() == true)
	{
		temp = new Btn<generic>;
		temp -> l = NULL;
		temp -> r = NULL;
		temp -> p = NULL;
		temp -> data = new generic(x);
		m_root = temp;
		m_size++;
	}
	else
	{
		Btn<generic> * temp1;
		temp1 = m_root;
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
		m_size++;
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
void Bst<generic>::remove (generic x, Btn<generic> * temp)
{	
	generic * tempData;		
	if((temp -> l) == NULL && (temp -> r) == NULL) //<-- Node is a LEAF
	{		
		if(temp == m_root) //<-- Node is at ROOT
		{
			delete temp -> data;
			delete temp;
			m_root = NULL;
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
			m_size--;
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
				m_size--;
				return;
			}
			else //<-- Node is not a LEAF
			{
				temp = temp2;
				remove(x, temp);
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
				m_size--;
				return;
			}
			else //<-- Node is not a LEAF
			{
				temp = temp2;
				remove(x, temp);
			}
		}
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn search (Btn<generic> * temp, generic x) 
/// @brief Returns memory location of data for object of type generic
/// equal to x 
/// @pre x is of a valid type
/// @post (none)
/// @param x object to be searched for in binary search tree
/// @param temp starting pointer for tree traversal
/// @return pointer to the data for x
//////////////////////////////////////////////////////////////////////
Btn<generic>* Bst<generic>::search (generic x)
{	
	Btn<generic> * temp;
	temp = m_root;
	while(temp != NULL)
	{
		if(x > *(temp -> data))
		{
			temp = temp -> r;
		}				
		else if(x < *(temp -> data))
		{
			temp = temp -> l;
		}
		else if(*(temp -> data) == x)
		{
			return temp;
		}
	}
	if(temp == NULL)
	{
		throw Exception
		(
			ITEM_NOT_EXIST,
			"Item does not exist in the binary search tree."
		 );
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn clear () 
/// @brief Removes all of the data in the binary search tree
/// @pre (none)
/// @post (none)
/// @return void 
//////////////////////////////////////////////////////////////////////
void Bst<generic>::clear ()
{
	while(m_root != NULL)
	{
		remove(*(m_root -> data), m_root);
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn empty () 
/// @brief Returns true if the binary search tree is empty, false if
/// otherwise
/// @pre (none)
/// @post (none)
/// @return void 
//////////////////////////////////////////////////////////////////////
bool Bst<generic>::empty ()
{
	if(m_root == NULL)
	{
		return true;
	}
	return false;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn size () 
/// @brief Returns the number of items in the binary search tree
/// @pre (none)
/// @post (none)
/// @return void 
//////////////////////////////////////////////////////////////////////
unsigned int Bst<generic>::size ()
{
	return m_size;
}
