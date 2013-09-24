////////////////////////////////////////////////////////////////////// 
/// @file slist.h 
/// @author Maximilian Schroeder
/// @brief Header file for class SList
//////////////////////////////////////////////////////////////////////
#ifndef SLIST_H
#define SLIST_H

#include "exception.h"
#include "snode.h"
#include "slistiterator.h"

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @class SList
/// @brief Singly-linked list with dynamic size
////////////////////////////////////////////////////////////////////// 
class SList
{
public:
    SList ();
    SList (SList &);
    ~SList ();
    SList & operator= (const SList &);	
    void push_front (generic);
    void pop_front ();
    void remove (generic);
    generic & front ();
    void clear ();
    unsigned int size () const;
    bool empty () const;
	typedef SListIterator<generic> Iterator;	
	Iterator begin () const;
    Iterator end () const;
	
private:
    unsigned int m_size;       ///< holds current size of the singly-linked list
    SNode<generic> * m_front;  ///< holds head pointer of the singly-linked list
};

#include "slist.hpp"
#endif
