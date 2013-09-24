////////////////////////////////////////////////////////////////////// 
/// @file stack.hpp 
/// @author Maximilian Schroeder
/// @brief Implementation for the header file stack.h
//////////////////////////////////////////////////////////////////////

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn Stack () 
/// @brief Constructs an object of type Stack of size 0
/// @pre (none)
/// @post m_size = 0
/// @return void 
////////////////////////////////////////////////////////////////////// 
Stack<generic>::Stack () : SList<generic> ()
{	
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn Stack (Stack & x) 
/// @brief Constructs an object of type Stack that is a duplicate of
/// x in terms of size and contents
/// @pre x is a valid Stack
/// @post m_size = x.size()
/// @param x Stack to be copied onto target Stack
/// @return void 
////////////////////////////////////////////////////////////////////// 
Stack<generic>::Stack (Stack &x) : SList<generic> (x)
{
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn ~Stack () 
/// @brief Destructor for Stack class
/// @pre (none)
/// @post (none)
/// @return void 
//////////////////////////////////////////////////////////////////////
Stack<generic>::~Stack ()
{
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator= (const Stack & x) 
/// @brief Constructs an object of type Stack that is a duplicate of
/// x in terms of size and contents
/// @pre x is a valid Stack
/// @post m_size = x.size()
/// @param x Stack to be copied onto target Stack
/// @return copy of Stack on right side of operator
////////////////////////////////////////////////////////////////////// 
Stack<generic>& Stack<generic>::operator= (const Stack & x)
{
	(* this) = new Stack(x);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn push (generic x) 
/// @brief Inserts object of type generic at the front of the Stack
/// @pre x is of a valid type
/// @post (none)
/// @param x object to be inserted at front of Stack
/// @return void 
////////////////////////////////////////////////////////////////////// 
void Stack<generic>::push (generic x)
{
    SList<generic>::push_front (x);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn pop () 
/// @brief Removes the first object in the Stack
/// @pre m_size > 0
/// @post (none)
/// @return void 
////////////////////////////////////////////////////////////////////// 
void Stack<generic>::pop ()
{
	SList<generic>::pop_front ();
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn top () 
/// @brief Returns the data at the top of the Stack
/// @pre (none)
/// @post (none)
/// @return first object in Stack by reference
//////////////////////////////////////////////////////////////////////
generic& Stack<generic>::top ()
{
	SList<generic>::front ();
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn size () 
/// @brief Returns amount of items in the Stack
/// @pre (none)
/// @post (none)
/// @return size of the Stack
////////////////////////////////////////////////////////////////////// 
unsigned int Stack<generic>::size () const
{
	return (* this).SList<generic>::size();
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn empty () 
/// @brief Returns a boolean based on whether or not the Stack is
/// empty
/// @pre (none)
/// @post (none)
/// @return true if Stack is empty, false if otherwise 
//////////////////////////////////////////////////////////////////////
bool Stack<generic>::empty () const
{
	if((* this).size() == 0)
	{
		return true;
	}
	return false;
}
