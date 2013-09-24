////////////////////////////////////////////////////////////////////// 
/// @file listiterator.h 
/// @author Maximilian Schroeder
/// @brief Header file for class ListIterator
//////////////////////////////////////////////////////////////////////
#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "node.h"

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @class ListIterator
/// @brief Iterator to search through a List
//////////////////////////////////////////////////////////////////////
class ListIterator
{
public:
    ListIterator ();
    ListIterator (Node<generic> *);
    generic operator* () const;
    ListIterator operator++ ();
    ListIterator operator++ (int);
    ListIterator operator-- ();
    ListIterator operator-- (int);
    bool operator== (const ListIterator &) const;
    bool operator!= (const ListIterator &) const;
	
private:
    Node<generic> * m_current;   ///< holds pointer which points at 
	                             ///  current position in List
};

#include "listiterator.hpp"
#endif
