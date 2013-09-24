#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////////// 
/// @file list.hpp 
/// @author Maximilian Schroeder
/// @brief Implementation for the header file list.h
//////////////////////////////////////////////////////////////////////

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn List () 
/// @brief Constructs an object of type List of size 0
/// @pre (none)
/// @post m_size = 0
/// @return void 
////////////////////////////////////////////////////////////////////// 
List<generic>::List ()
{
	m_size = 0;
	m_front = NULL;
	m_back = NULL;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn List (List & x) 
/// @brief Constructs an object of type List that is a duplicate of
/// x in terms of size and contents
/// @pre x is a valid List
/// @post m_size = x.size()
/// @param x List to be copied onto target List
/// @return void 
////////////////////////////////////////////////////////////////////// 
List<generic>::List (List & x) : m_size(0), m_front(NULL), m_back(NULL)
{
	(* this) = x;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn ~List () 
/// @brief Destructor for List class
/// @pre (none)
/// @post (none)
/// @return void 
////////////////////////////////////////////////////////////////////// 
List<generic>::~List ()
{
	clear();
	m_front = NULL;
	m_back = NULL;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator= (const List & x) 
/// @brief Constructs an object of type List that is a duplicate of
/// x in terms of size and contents
/// @pre x is a valid List
/// @post m_size = x.size()
/// @param x List to be copied onto target List
/// @return copy of List on right side of operator
////////////////////////////////////////////////////////////////////// 
List<generic>& List<generic>::operator= (const List & x)
{
	clear();
	
	for(Iterator i = x.begin(); i != x.end(); i++)
	{	
		push_back(* i);
	}
	push_back(* x.end());
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn push_front (generic x) 
/// @brief Inserts object of type generic at the front of the 
/// doubly-linked list
/// @pre x is of a valid type
/// @post (none)
/// @param x object to be inserted at front of list
/// @return void 
////////////////////////////////////////////////////////////////////// 
void List<generic>::push_front (generic x)
{
	if(m_size == 0)
	{
		push_back (x);
	}
	else
	{
		Node<generic> * temp = m_front;
		m_front = new Node<generic>;
		m_front -> data = x;		
		m_front -> b = temp;
		m_front -> f = NULL;
		temp -> f = m_front;	
		m_size++;
		temp = NULL;
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn pop_front () 
/// @brief Removes the first object in the doubly-linked list
/// @pre m_size > 0
/// @post (none)
/// @return void 
////////////////////////////////////////////////////////////////////// 
void List<generic>::pop_front ()
{
	if(m_size == 0)
	{
		throw Exception
		(
		 CONTAINER_EMPTY,
		 "The linked list is empty. Cannot pop nonexistent item."
		);
	}
	else if(m_size == 1)
	{
		delete m_front;
		m_front = NULL;
		m_back = NULL;
		m_size--;
	}
	else
	{
		Node<generic> * temp = m_front;
		m_front = m_front -> b;
		delete temp;
		m_size--;
		temp = NULL;
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn push_back (generic x) 
/// @brief Inserts object of type generic at the back of the 
/// doubly-linked list
/// @pre x is of a valid type
/// @post (none)
/// @param x object to be inserted at back of list
/// @return void 
////////////////////////////////////////////////////////////////////// 
void List<generic>::push_back (generic x)
{
	if(m_size == 0)
	{
		m_back = new Node<generic>;
		m_back -> data = x;
		m_front = m_back;
		m_size++;
		m_back -> b = NULL;
		m_back -> f = NULL;
	}
	else
	{
		Node<generic> * temp = m_back;
		m_back = new Node<generic>;
		m_back -> data = x;
		m_back -> f = temp;
		m_back -> b = NULL;
		temp -> b = m_back;
		m_size++;
		temp = NULL;
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn pop_back () 
/// @brief Removes the last object in the doubly-linked list
/// @pre m_size > 0
/// @post (none)
/// @return void 
////////////////////////////////////////////////////////////////////// 
void List<generic>::pop_back ()
{
	if(m_size == 0)
	{
		throw Exception
		(
		 CONTAINER_EMPTY,
		 "The linked list is empty. Cannot pop nonexistent item."
		);
	}
	else if(m_size == 1)
	{
		pop_front ();
	}
	else
	{
		Node<generic> * temp = m_back;
		m_back = m_back -> f;
		delete temp;
		m_size--;
		temp = NULL;
	}	
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn remove (generic x) 
/// @brief Removes first instance of object x in the doubly-linked 
/// list
/// @pre x exists within doubly-linked list
/// @post (none)
/// @param x object to be removed from list
/// @return void 
////////////////////////////////////////////////////////////////////// 
void List<generic>::remove (generic x)
{
	if((* this).front() == x)
	{
		pop_front();
		return;
	}
	else if((* this).back() == x)
	{
		pop_back();
		return;
	}
	else
	{
		Node<generic> * temp1;
		for(temp1 = m_front; temp1 != NULL && temp1->data != x; temp1 = temp1->b);
		if(temp1 != NULL)
		{
			temp1 -> f -> b = temp1 -> b;
			temp1 -> b -> f = temp1 -> f;
			delete temp1;
			temp1 = NULL;
			m_size--;
			return;
		}
	}
	throw Exception
	(
	 ITEM_NOT_EXIST,
	 "Item does not exist within linked list. Cannot remove nonexistent item."
	);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn front () 
/// @brief Returns the data at the front of the linked list
/// @pre (none)
/// @post (none)
/// @return first object in linked list by reference
////////////////////////////////////////////////////////////////////// 
generic& List<generic>::front ()
{
	if(m_size == 0)
	{
		throw Exception
		(
		 CONTAINER_EMPTY,
		 "The linked list is empty. Cannot return nonexistent item."
		 );
	}
	return m_front -> data;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn back () 
/// @brief Returns the data at the back of the linked list
/// @pre (none)
/// @post (none)
/// @return last object in linked list by reference
////////////////////////////////////////////////////////////////////// 
generic& List<generic>::back ()
{
	if(m_size == 0)
	{
		throw Exception
		(
		 CONTAINER_EMPTY,
		 "The linked list is empty. Cannot return nonexistent item."
		 );
	}
	return m_back -> data;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn clear () 
/// @brief Deletes all values in doubly-linked list
/// @pre (none)
/// @post m_front = NULL
/// @return void 
////////////////////////////////////////////////////////////////////// 
void List<generic>::clear ()
{
	while(m_front != NULL)
	{
		pop_front();
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn size () 
/// @brief Returns amount of items in the doubly-linked list
/// @pre (none)
/// @post (none)
/// @return size of the list
////////////////////////////////////////////////////////////////////// 
unsigned int List<generic>::size () const
{
	return m_size;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn empty () 
/// @brief Returns a boolean based on whether or not the doubly-linked
/// list is empty
/// @pre (none)
/// @post (none)
/// @return true if list is empty, false if otherwise 
////////////////////////////////////////////////////////////////////// 
bool List<generic>::empty () const
{
	if(m_size == 0)
	{
		return true;
	}
	return false;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn begin () 
/// @brief Returns an ListIterator pointing at the first node of an List
/// @pre (none)
/// @post (none)
/// @return pointer that points at beginning of List 
////////////////////////////////////////////////////////////////////// 
ListIterator<generic> List<generic>::begin () const
{
	return ListIterator<generic> (m_front);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn end () 
/// @brief Returns an ListIterator pointing to NULL
/// @pre (none)
/// @post (none)
/// @return pointer that points to NULL
////////////////////////////////////////////////////////////////////// 
ListIterator<generic> List<generic>::end () const
{
	return ListIterator<generic> (m_back);
}
