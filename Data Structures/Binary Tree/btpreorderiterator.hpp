////////////////////////////////////////////////////////////////////// 
/// @file btpreorderiterator.hpp
/// @author Maximilian Schroeder
/// @brief Implementation of header file btpreorderiterator.h
//////////////////////////////////////////////////////////////////////

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn BTPreorderIterator () 
/// @brief Constructs an object of type BTPreorderIterator that 
/// points at NULL
/// @pre (none)
/// @post m_current = NULL
/// @return void 
////////////////////////////////////////////////////////////////////// 
BTPreorderIterator<generic>::BTPreorderIterator () : m_current (NULL)
{	
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn BTPreorderIterator (Btn<generic> * x) 
/// @brief Constructs an object of type BTPreorderIterator with 
/// m_current equal to x
/// @pre (none)
/// @post m_current = x
/// @param x pointer to be stored in m_current
/// @return void 
////////////////////////////////////////////////////////////////////// 
BTPreorderIterator<generic>::BTPreorderIterator (Btn<generic> * x) : m_current (x)
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
generic BTPreorderIterator<generic>::operator* () const
{
	return *(m_current -> data);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator++ () 
/// @brief Returns the next binary tree node using the Preorder 
/// search algorithm
/// @pre (none)
/// @post (none)
/// @return Next binary tree node using the Preorder search
////////////////////////////////////////////////////////////////////// 
BTPreorderIterator<generic> BTPreorderIterator<generic>::operator++ ()
{
	if(m_current -> l != NULL)
	{
		m_current = m_current -> l;
	}
	else if(m_current -> l == NULL && m_current -> r != NULL)
	{
		m_current = m_current -> r;
	}
	else if(m_current -> l == NULL && m_current -> r == NULL)
	{
		while(m_current -> p -> r == NULL || m_current -> p -> r == m_current)
		{
			m_current = m_current -> p;
		}
		m_current = m_current -> p -> r;
	}	
	return (* this);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator++ (int) 
/// @brief Returns the next binary tree node using the Preorder 
/// search algorithm (pre-increment)
/// @pre (none)
/// @post (none)
/// @return Next binary tree node using the Preorder search
//////////////////////////////////////////////////////////////////////
BTPreorderIterator<generic> BTPreorderIterator<generic>::operator++ (int)
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
Btn<generic>* BTPreorderIterator<generic>::current () const
{
	return m_current;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator== (const BTPreorderIterator & rhs) const
/// @brief Returns a boolean based on expression which called operator
/// @pre (none)
/// @post (none)
/// @return True if expression is true, false if otherwise
//////////////////////////////////////////////////////////////////////
bool BTPreorderIterator<generic>::operator== (const BTPreorderIterator & rhs) const
{
	return m_current == rhs.m_current;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator!= (const BTPreorderIterator & rhs) const
/// @brief Returns a boolean based on expression which called operator
/// @pre (none)
/// @post (none)
/// @return True if expression is false, false if otherwise
//////////////////////////////////////////////////////////////////////
bool BTPreorderIterator<generic>::operator!= (const BTPreorderIterator & rhs) const
{
	return m_current != rhs.m_current;
}
