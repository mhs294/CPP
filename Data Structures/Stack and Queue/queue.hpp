////////////////////////////////////////////////////////////////////// 
/// @file queue.hpp 
/// @author Maximilian Schroeder
/// @brief Implementation for the header file queue.h
//////////////////////////////////////////////////////////////////////

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn Queue () 
/// @brief Constructs an object of type Queue of size 0
/// @pre (none)
/// @post m_size = 0
/// @return void 
////////////////////////////////////////////////////////////////////// 
Queue<generic>::Queue () : List<generic> ()
{
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn Queue (Queue & x) 
/// @brief Constructs an object of type List that is a duplicate of
/// x in terms of size and contents
/// @pre x is a valid Queue
/// @post m_size = x.size()
/// @param x Queue to be copied onto target Queue
/// @return void 
////////////////////////////////////////////////////////////////////// 
Queue<generic>::Queue (Queue & x) : List<generic> (x)
{
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn ~Queue () 
/// @brief Destructor for Queue class
/// @pre (none)
/// @post (none)
/// @return void 
////////////////////////////////////////////////////////////////////// 
Queue<generic>::~Queue ()
{
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator= (const Queue & x) 
/// @brief Constructs an object of type Queue that is a duplicate of
/// x in terms of size and contents
/// @pre x is a valid Queue
/// @post m_size = x.size()
/// @param x Queue to be copied onto target Queue
/// @return copy of Queue on right side of operator
////////////////////////////////////////////////////////////////////// 
Queue<generic>& Queue<generic>::operator= (const Queue & x)
{
	(* this) = new Queue(x);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn empty () 
/// @brief Returns a boolean based on whether or not the Queue is 
/// empty
/// @pre (none)
/// @post (none)
/// @return true if Queue is empty, false if otherwise 
//////////////////////////////////////////////////////////////////////
bool Queue<generic>::empty () const
{
	if((* this).size() == 0)
	{
		return true;
	}
	return false;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn size () 
/// @brief Returns amount of items in the Queue
/// @pre (none)
/// @post (none)
/// @return size of the Queue
//////////////////////////////////////////////////////////////////////
unsigned int Queue<generic>::size () const
{
	return (* this).List<generic>::size();
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn front () 
/// @brief Returns the data at the front of the Queue
/// @pre (none)
/// @post (none)
/// @return first object in Queue by reference
////////////////////////////////////////////////////////////////////// 
generic& Queue<generic>::front ()
{
	List<generic>::front ();
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn back () 
/// @brief Returns the data at the back of the Queue
/// @pre (none)
/// @post (none)
/// @return last object in Queue by reference
////////////////////////////////////////////////////////////////////// 
generic& Queue<generic>::back ()
{
	List<generic>::back ();
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn push (generic x) 
/// @brief Inserts object of type generic at the back of the Queue
/// @pre x is of a valid type
/// @post (none)
/// @param x object to be inserted at back of Queue
/// @return void 
////////////////////////////////////////////////////////////////////// 
void Queue<generic>::push (generic x)
{
	List<generic>::push_back (x);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn pop () 
/// @brief Removes the first object in the Queue
/// @pre m_size > 0
/// @post (none)
/// @return void 
////////////////////////////////////////////////////////////////////// 
void Queue<generic>::pop ()
{
	List<generic>::pop_front ();
}
