////////////////////////////////////////////////////////////////////// 
/// @file slistiterator.h 
/// @author Maximilian Schroeder
/// @brief Header file for class SListIterator
//////////////////////////////////////////////////////////////////////
#ifndef SLISTITERATOR_H
#define SLISTITERATOR_H

#include "snode.h"

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @class SListIterator
/// @brief Iterator to search through an SList
////////////////////////////////////////////////////////////////////// 
class SListIterator
{
public:
    SListIterator ();
    SListIterator (SNode<generic> *);
    generic operator* () const;
    SListIterator operator++ ();
    SListIterator operator++ (int);
    bool operator== (const SListIterator &) const;
    bool operator!= (const SListIterator &) const;
	
private:
    SNode<generic> * m_current;  ///< holds pointer which points at 
	                             ///  current position in SList
};

#include "slistiterator.hpp"
#endif
