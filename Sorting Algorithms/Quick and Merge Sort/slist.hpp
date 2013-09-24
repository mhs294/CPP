////////////////////////////////////////////////////////////////////// 
/// @file slist.hpp 
/// @author Maximilian Schroeder
/// @brief Implementation for the header file slist.h
//////////////////////////////////////////////////////////////////////

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn SList () 
/// @brief Constructs an object of type SList of size 0
/// @pre (none)
/// @post m_size = 0
/// @return void 
////////////////////////////////////////////////////////////////////// 
SList<generic>::SList ()
{
	m_size = 0;
	m_front = NULL;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn SList (SList & x) 
/// @brief Constructs an object of type SList that is a duplicate of
/// x in terms of size and contents
/// @pre x is a valid SList
/// @post m_size = x.size()
/// @param x SList to be copied onto target SList
/// @return void 
////////////////////////////////////////////////////////////////////// 
SList<generic>::SList (SList & x)
{
	(* this) = x;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn ~SList () 
/// @brief Destructor for SList class
/// @pre (none)
/// @post (none)
/// @return void 
////////////////////////////////////////////////////////////////////// 
SList<generic>::~SList ()
{
	(* this).clear();
	m_front = NULL;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator= (const SList & x) 
/// @brief Constructs an object of type SList that is a duplicate of
/// x in terms of size and contents
/// @pre x is a valid SList
/// @post m_size = x.size()
/// @param x SList to be copied onto target SList
/// @return copy of SList on right side of operator
////////////////////////////////////////////////////////////////////// 
SList<generic>& SList<generic>::operator= (const SList & x)
{
	m_size = 0;
	m_front = NULL;
	SList<generic> temp;
	for(Iterator i = x.begin(); i != x.end(); i++)
	{	
		temp.push_front(* i);
	}
	for(Iterator i = temp.begin(); i != temp.end(); i++)
	{	
		push_front(* i);
	}
	temp.clear();
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn push_front (generic x) 
/// @brief Inserts object of type generic at the front of the 
/// singly-linked list
/// @pre x is of a valid type
/// @post (none)
/// @param x object to be inserted at front of list
/// @return void 
////////////////////////////////////////////////////////////////////// 
void SList<generic>::push_front (generic x)
{
	SNode<generic> * temp = m_front;
	m_front = new SNode<generic>;
	m_front -> data = x;
	m_front -> b = temp;
	m_size++;
	temp = NULL;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn pop_front () 
/// @brief Removes the first object in the singly-linked list
/// @pre m_size > 0
/// @post (none)
/// @return void 
////////////////////////////////////////////////////////////////////// 
void SList<generic>::pop_front ()
{
	if(m_size == 0)
	{
		throw Exception
		(
			CONTAINER_EMPTY,
			"The linked list is empty. Cannot pop nonexistent item."
		);
	}
	SNode<generic> * temp = m_front;
	m_front = m_front -> b;
	delete temp;
	m_size--;
	temp = NULL;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn remove (generic x) 
/// @brief Removes first instance of object x in the singly-linked 
/// list
/// @pre x exists within singly-linked list
/// @post (none)
/// @param x object to be removed from list
/// @return void 
////////////////////////////////////////////////////////////////////// 
void SList<generic>::remove (generic x)
{
	if((* this).front() == x)
	{
		pop_front();
		return;
	}
	else
	{
		SNode<generic> * temp1;
		SNode<generic> * temp2;	
		temp1 = m_front;
		for(Iterator i = (* this).begin(); i != (* this).end(); i++)
		{
			temp2 = temp1 -> b;			
			if(temp2 -> data == x)
			{
				temp1 -> b = temp2 -> b;
				delete temp2;
				temp2 = NULL;
				temp1 = NULL;
				m_size--;
				return;
			}
			if(temp2 -> b != NULL)
			{
				temp1 = temp1 -> b;
			}
		}
		temp2 = NULL;
		temp1 = NULL;
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
generic& SList<generic>::front ()
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
/// @fn clear () 
/// @brief Deletes all values in singly-linked list
/// @pre (none)
/// @post m_front = NULL
/// @return void 
////////////////////////////////////////////////////////////////////// 
void SList<generic>::clear ()
{
	while(m_front != NULL)
	{
		pop_front();
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn size () 
/// @brief Returns amount of items in the singly-linked list
/// @pre (none)
/// @post (none)
/// @return size of the list
////////////////////////////////////////////////////////////////////// 
unsigned int SList<generic>::size () const
{
	return m_size;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn empty () 
/// @brief Returns a boolean based on whether or not the singly-linked
/// list is empty
/// @pre (none)
/// @post (none)
/// @return true if list is empty, false if otherwise 
////////////////////////////////////////////////////////////////////// 
bool SList<generic>::empty () const
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
/// @brief Returns an SListIterator pointing at the first node of an SList
/// @pre (none)
/// @post (none)
/// @return pointer that points at beginning of SList 
////////////////////////////////////////////////////////////////////// 
SListIterator<generic> SList<generic>::begin () const
{
	return SListIterator<generic> (m_front);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn end () 
/// @brief Returns an SListIterator pointing to NULL
/// @pre (none)
/// @post (none)
/// @return pointer that points to NULL
////////////////////////////////////////////////////////////////////// 
SListIterator<generic> SList<generic>::end () const
{
	return SListIterator<generic> ();
}
