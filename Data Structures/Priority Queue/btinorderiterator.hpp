////////////////////////////////////////////////////////////////////// 
/// @file btinorderiterator.hpp
/// @author Maximilian Schroeder
/// @brief Implementation of header file btinorderiterator.h
//////////////////////////////////////////////////////////////////////

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn BTInorderIterator () 
/// @brief Constructs an object of type BTInorderIterator that points 
/// at NULL
/// @pre (none)
/// @post m_current = NULL
/// @return void 
////////////////////////////////////////////////////////////////////// 
BTInorderIterator<generic>::BTInorderIterator () : m_current (NULL)
{	
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn BTInorderIterator (Btn<generic> * x) 
/// @brief Constructs an object of type BTInorderIterator with 
/// m_current equal to x
/// @pre (none)
/// @post m_current = x
/// @param x pointer to be stored in m_current
/// @return void 
////////////////////////////////////////////////////////////////////// 
BTInorderIterator<generic>::BTInorderIterator (Btn<generic> * x) : m_current (x)
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
generic BTInorderIterator<generic>::operator* () const
{
	return *(m_current -> data);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator++ () 
/// @brief Returns the next binary tree node using the InOrder search
/// algorithm
/// @pre (none)
/// @post (none)
/// @return Next binary tree node using the InOrder search
////////////////////////////////////////////////////////////////////// 
BTInorderIterator<generic> BTInorderIterator<generic>::operator++ ()
{
	if(m_current -> l == NULL && m_current -> r == NULL && m_current -> p -> l == m_current)
	{
		m_current = m_current -> p;
	}
	else if(m_current -> l == NULL && m_current -> r == NULL && m_current -> p -> r == m_current)
	{
		while(m_current -> p -> r == m_current)
		{
			m_current = m_current -> p;
		}
		m_current = m_current -> p;
	}
	else if(m_current -> r != NULL)
	{
		m_current = m_current -> r;
		while(m_current -> l != NULL)
		{
			m_current = m_current -> l;
		}
	}	
	else if(m_current -> r ==  NULL && m_current -> l != NULL)
	{
		while(m_current -> p -> r == m_current)
		{
			m_current = m_current -> p;
		}
		m_current = m_current -> p;
	}
	return (* this);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator++ (int) 
/// @brief Returns the next binary tree node using the InOrder search
/// algorithm (pre-increment)
/// @pre (none)
/// @post (none)
/// @return Next binary tree node using the InOrder search
//////////////////////////////////////////////////////////////////////
BTInorderIterator<generic> BTInorderIterator<generic>::operator++ (int)
{
	return ++(* this);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn current () 
/// @brief Returns pointer which points at node iterator is pointing
/// to
/// @pre (none)
/// @post (none)
/// @return Pointer which points at node iterator is pointing to
////////////////////////////////////////////////////////////////////// 
Btn<generic>* BTInorderIterator<generic>::current() const
{
	return m_current;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator== (const BTInorderIterator & rhs) const
/// @brief Returns a boolean based on expression which called operator
/// @pre (none)
/// @post (none)
/// @return True if expression is true, false if otherwise
//////////////////////////////////////////////////////////////////////
bool BTInorderIterator<generic>::operator== (const BTInorderIterator & rhs) const
{
	return m_current == rhs.m_current;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator!= (const BTInorderIterator & rhs) const
/// @brief Returns a boolean based on expression which called operator
/// @pre (none)
/// @post (none)
/// @return True if expression is false, false if otherwise
//////////////////////////////////////////////////////////////////////
bool BTInorderIterator<generic>::operator!= (const BTInorderIterator & rhs) const
{
	return m_current != rhs.m_current;
}
