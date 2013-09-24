////////////////////////////////////////////////////////////////////// 
/// @file btinorderiterator.h 
/// @author Maximilian Schroeder
/// @brief Header file for class BTInorderIterator
//////////////////////////////////////////////////////////////////////
#ifndef BTINORDERITERATOR_H
#define BTINORDERITERATOR_H

#include "btn.h"

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @class BTInorderIterator
/// @brief Binary Tree Iterator using InOrder algorithm
//////////////////////////////////////////////////////////////////////
class BTInorderIterator
{
public:
    BTInorderIterator ();
    BTInorderIterator (Btn<generic> *);
    generic operator* () const;
    BTInorderIterator operator++ ();
    BTInorderIterator operator++ (int);
	Btn<generic> * current() const;
    bool operator== (const BTInorderIterator &) const;
    bool operator!= (const BTInorderIterator &) const;
	
private:
	Btn<generic> * m_current;  //<-- Holds the current position of
	                           //    the Iterator in the binary tree
};

#include "btinorderiterator.hpp"
#endif
