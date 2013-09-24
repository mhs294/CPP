////////////////////////////////////////////////////////////////////// 
/// @file btpreorderiterator.h 
/// @author Maximilian Schroeder
/// @brief Header file for class BTPreOrderIterator
//////////////////////////////////////////////////////////////////////
#ifndef BTPREORDERITERATOR_H
#define BTPREORDERITERATOR_H

#include "btn.h"

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @class BTPreOrderIterator
/// @brief Binary Tree Iterator using PreOrder algorithm
//////////////////////////////////////////////////////////////////////
class BTPreorderIterator
{
public:
    BTPreorderIterator ();
    BTPreorderIterator (Btn<generic> *);
    generic operator* () const;
    BTPreorderIterator operator++ ();
    BTPreorderIterator operator++ (int);
	Btn<generic>* current () const;
    bool operator== (const BTPreorderIterator &) const;
    bool operator!= (const BTPreorderIterator &) const;
	
private:
	Btn<generic> * m_current;  //<-- Holds the current position of
	                           //    the Iterator in the binary tree
};

#include "btpreorderiterator.hpp"
#endif
