////////////////////////////////////////////////////////////////////// 
/// @file btpostorderiterator.hpp
/// @author Maximilian Schroeder
/// @brief Implementation of header file btpostorderiterator.h
//////////////////////////////////////////////////////////////////////

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn BTPostorderIterator () 
/// @brief Constructs an object of type BTPostorderIterator that 
/// points at NULL
/// @pre (none)
/// @post m_current = NULL
/// @return void 
////////////////////////////////////////////////////////////////////// 
BTPostorderIterator<generic>::BTPostorderIterator () : m_current (NULL)
{	
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn BTPostorderIterator (Btn<generic> * x) 
/// @brief Constructs an object of type BTPostorderIterator with 
/// m_current equal to x
/// @pre (none)
/// @post m_current = x
/// @param x pointer to be stored in m_current
/// @return void 
////////////////////////////////////////////////////////////////////// 
BTPostorderIterator<generic>::BTPostorderIterator (Btn<generic> * x) : m_current (x)
{	
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn opertator* () 
/// @brief Returns data stored by current binary tree node
/// @pre (none)
/// @post (none)
/// @return The data stored in the current binary tree node
////////////////////////////////////////////////////////////////////// 
generic BTPostorderIterator<generic>::operator* () const
{
	return *(m_current -> data);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator++ () 
/// @brief Returns the next binary tree node using the Postorder 
/// search algorithm
/// @pre (none)
/// @post (none)
/// @return Next binary tree node using the Postorder search
////////////////////////////////////////////////////////////////////// 
BTPostorderIterator<generic> BTPostorderIterator<generic>::operator++ ()
{
	if(m_current -> p -> l == m_current)
	{
		m_current = m_current -> p;
		while(m_current -> r != NULL)
		{
			m_current = m_current -> r;
			while(m_current -> l != NULL)
			{
				m_current = m_current -> l;
			}
		}
	}
	else if(m_current -> p -> r == m_current)
	{
		m_current = m_current -> p;
	}	
	return (* this);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator++ (int) 
/// @brief Returns the next binary tree node using the Postorder 
/// search algorithm (pre-increment)
/// @pre (none)
/// @post (none)
/// @return Next binary tree node using the Postorder search
//////////////////////////////////////////////////////////////////////
BTPostorderIterator<generic> BTPostorderIterator<generic>::operator++ (int)
{
	return ++(* this);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn current () const 
/// @brief Returns a pointer pointing to the current position of the
/// iterator
/// @pre (none)
/// @post (none)
/// @return Pointer whose address target matches that of the iterator
//////////////////////////////////////////////////////////////////////
Btn<generic>* BTPostorderIterator<generic>::current () const
{
	return m_current;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator== (const BTPostorderIterator & rhs) const
/// @brief Returns a boolean based on expression which called operator
/// @pre (none)
/// @post (none)
/// @return True if expression is true, false if otherwise
//////////////////////////////////////////////////////////////////////
bool BTPostorderIterator<generic>::operator== (const BTPostorderIterator & rhs) const
{
	return m_current == rhs.m_current;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator!= (const BTPostorderIterator & rhs) const
/// @brief Returns a boolean based on expression which called operator
/// @pre (none)
/// @post (none)
/// @return True if expression is false, false if otherwise
//////////////////////////////////////////////////////////////////////
bool BTPostorderIterator<generic>::operator!= (const BTPostorderIterator & rhs) const
{
	return m_current != rhs.m_current;
}
