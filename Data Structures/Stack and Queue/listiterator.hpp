////////////////////////////////////////////////////////////////////// 
/// @file listiterator.hpp 
/// @author Maximilian Schroeder
/// @brief Implementation for the header file listiterator.h
//////////////////////////////////////////////////////////////////////

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn ListIterator () 
/// @brief Constructs an object of type ListIterator that points at 
/// NULL
/// @pre (none)
/// @post m_current = NULL
/// @return void 
////////////////////////////////////////////////////////////////////// 
ListIterator<generic>::ListIterator () : m_current (NULL)
{
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn List (Node<generic> * x) 
/// @brief Constructs an object of type ListIterator with m_current
/// equal to x
/// @pre (none)
/// @post m_current = x
/// @param x pointer to be stored in m_current
/// @return void 
////////////////////////////////////////////////////////////////////// 
ListIterator<generic>::ListIterator (Node<generic> * x) : m_current (x)
{
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator* () const 
/// @brief Operator that returns the data m_current is pointing at
/// @pre (none)
/// @post (none)
/// @return data in List pointed by m_current 
////////////////////////////////////////////////////////////////////// 
generic ListIterator<generic>::operator* () const
{
    return m_current -> data;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator++ () 
/// @brief Moves the Iterator which called operator to point at next
/// item in the List (post-increment)
/// @pre (none)
/// @post (none)
/// @return pointer which points at the next item in the List 
////////////////////////////////////////////////////////////////////// 
ListIterator<generic> ListIterator<generic>::operator++ ()
{
    m_current = m_current -> b;
    return *this;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator++ (int) 
/// @brief Moves the Iterator which called operator to point at next
/// item in the List (pre-increment)
/// @pre (none)
/// @post (none)
/// @return pointer which points at the next item in the List 
//////////////////////////////////////////////////////////////////////  
ListIterator<generic> ListIterator<generic>::operator++ (int)
{
    return ++(* this);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator-- () 
/// @brief Moves the Iterator which called operator to point at 
/// previous item in the List (post-increment)
/// @pre (none)
/// @post (none)
/// @return pointer which points at the previous item in the List 
////////////////////////////////////////////////////////////////////// 
ListIterator<generic> ListIterator<generic>::operator-- ()
{
	m_current = m_current -> f;
    return *this;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator-- (int) 
/// @brief Moves the Iterator which called operator to point at 
/// previous item in the List (pre-increment)
/// @pre (none)
/// @post (none)
/// @return pointer which points at the previous item in the List 
////////////////////////////////////////////////////////////////////// 
ListIterator<generic> ListIterator<generic>::operator-- (int)
{
	return --(* this);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator== (const ListIterator & rhs) const 
/// @brief Returns a boolean based on whether two pointers are 
/// pointing at the same item in the List
/// @pre (none)
/// @post (none)
/// @param rhs is the pointer compared against the pointer that called
/// the operator (the left hand side)
/// @return true if pointers point at same item, false if not
////////////////////////////////////////////////////////////////////// 
bool ListIterator<generic>::operator== (const ListIterator<generic> & rhs) const
{
    return m_current == rhs.m_current;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator!= (const ListIterator & rhs) const 
/// @brief Returns a boolean based on whether two pointers are not
/// pointing at the same item in the List
/// @pre (none)
/// @post (none)
/// @param rhs is the pointer compared against the pointer that called
/// the operator (the left hand side)
/// @return true if pointers do not point at same item, false if they
/// do point at the same item
////////////////////////////////////////////////////////////////////// 
bool ListIterator<generic>::operator!= (const ListIterator<generic> & rhs) const
{
    return m_current != rhs.m_current;
}
