////////////////////////////////////////////////////////////////////// 
/// @file list.h 
/// @author Maximilian Schroeder
/// @brief Header file for class List
//////////////////////////////////////////////////////////////////////
#ifndef LIST_H
#define LIST_H

#include "listiterator.h"
#include "exception.h"
#include "node.h"

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @class List
/// @brief Doubly-linked list with dynamic size
////////////////////////////////////////////////////////////////////// 
class List
{
public:
    List ();
    List (List &);
    ~List ();
    List & operator= (const List &);
    void push_front (generic);
    void pop_front ();
    void push_back (generic);
    void pop_back ();
    void remove (generic);
    generic & front ();
    generic & back ();
    void clear ();
    unsigned int size () const;
    bool empty () const;
    typedef ListIterator<generic> Iterator;
    Iterator begin () const;
    Iterator end () const;
	
private:
    unsigned int m_size;       ///< holds the size of the linked list
    Node<generic> * m_front;   ///< holds head pointer for the linked list
    Node<generic> * m_back;    ///< holds tail pointer for the linked list
};

#include "list.hpp"
#endif
