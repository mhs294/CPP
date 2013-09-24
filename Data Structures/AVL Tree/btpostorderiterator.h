////////////////////////////////////////////////////////////////////// 
/// @file btpostorderiterator.h 
/// @author Maximilian Schroeder
/// @brief Header file for class BTPostOrderIterator
//////////////////////////////////////////////////////////////////////
#ifndef BTPOSTORDERITERATOR_H
#define BTPOSTORDERITERATOR_H

#include "btn.h"

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @class BTPostOrderIterator
/// @brief Binary Tree Iterator using PostOrder algorithm
//////////////////////////////////////////////////////////////////////
class BTPostorderIterator
{
public:
    BTPostorderIterator ();
    BTPostorderIterator (Btn<generic> *);
    generic operator* () const;
    BTPostorderIterator operator++ ();
    BTPostorderIterator operator++ (int);
	Btn<generic>* current () const;
    bool operator== (const BTPostorderIterator &) const;
    bool operator!= (const BTPostorderIterator &) const;
	
private:
	Btn<generic> * m_current;  //<-- Holds the current position of
							   //    the Iterator in the binary tree
};

#include "btpostorderiterator.hpp"
#endif
