////////////////////////////////////////////////////////////////////// 
/// @file slistiterator.hpp 
/// @author Maximilian Schroeder
/// @brief Implementation for the header file slistiterator.h
//////////////////////////////////////////////////////////////////////

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn SListIterator () 
/// @brief Constructs an object of type SListIterator that points at 
/// NULL
/// @pre (none)
/// @post m_current = NULL
/// @return void 
////////////////////////////////////////////////////////////////////// 
SListIterator<generic>::SListIterator () : m_current (NULL)
{
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn SList (SNode<generic> * x) 
/// @brief Constructs an object of type SListIterator with m_current
/// equal to x
/// @pre (none)
/// @post m_current = x
/// @param x pointer to be stored in m_current
/// @return void 
////////////////////////////////////////////////////////////////////// 
SListIterator<generic>::SListIterator (SNode<generic> * x) : m_current (x)
{
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator* () const 
/// @brief Operator that returns the data m_current is pointing at
/// @pre (none)
/// @post (none)
/// @return data in SList pointed by m_current 
////////////////////////////////////////////////////////////////////// 
generic SListIterator<generic>::operator* () const
{
    return m_current -> data;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator++ () 
/// @brief Moves the Iterator which called operator to point at next
/// item in the SList (post-increment)
/// @pre (none)
/// @post (none)
/// @return pointer which points at the next item in the SList 
////////////////////////////////////////////////////////////////////// 
SListIterator<generic> SListIterator<generic>::operator++ ()
{
    m_current = m_current -> b;
    return *this;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator++ (int) 
/// @brief Moves the Iterator which called operator to point at next
/// item in the SList (pre-increment)
/// @pre (none)
/// @post (none)
/// @return pointer which points at the next item in the SList 
//////////////////////////////////////////////////////////////////////  
SListIterator<generic> SListIterator<generic>::operator++ (int)
{
    return ++(* this);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator== (const SListIterator & rhs) const 
/// @brief Returns a boolean based on whether two pointers are 
/// pointing at the same item in the SList
/// @pre (none)
/// @post (none)
/// @param rhs is the pointer compared against the pointer that called
/// the operator (the left hand side)
/// @return true if pointers point at same item, false if not
////////////////////////////////////////////////////////////////////// 
bool SListIterator<generic>::operator== (const SListIterator<generic> & rhs) const
{
    return m_current == rhs.m_current;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator!= (const SListIterator & rhs) const 
/// @brief Returns a boolean based on whether two pointers are not
/// pointing at the same item in the SList
/// @pre (none)
/// @post (none)
/// @param rhs is the pointer compared against the pointer that called
/// the operator (the left hand side)
/// @return true if pointers do not point at same item, false if they
/// do point at the same item
////////////////////////////////////////////////////////////////////// 
bool SListIterator<generic>::operator!= (const SListIterator<generic> & rhs) const
{
    return m_current != rhs.m_current;
}
