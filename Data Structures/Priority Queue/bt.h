////////////////////////////////////////////////////////////////////// 
/// @file bt.h 
/// @author Maximilian Schroeder
/// @brief Header file for class BT
//////////////////////////////////////////////////////////////////////
#ifndef BT_H
#define BT_H

#include "btn.h"
#include "exception.h"
#include "btpreorderiterator.h"
#include "btinorderiterator.h"
#include "btpostorderiterator.h"

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @class BT
/// @brief Binary Search Tree that supports iterator capability
//////////////////////////////////////////////////////////////////////
class BT
{
public:
    BT();
    ~BT();
    BT(BT &);
    BT & operator= (const BT &);
    void clear ();
    bool empty ();
    unsigned int size ();
    typedef BTPreorderIterator<generic> PreOrder;
    typedef BTInorderIterator<generic> InOrder;
    typedef BTPostorderIterator<generic> PostOrder;
    PreOrder pre_begin () const;
    PreOrder pre_end () const;
    InOrder in_begin () const;
    InOrder in_end () const;
    PostOrder post_begin () const;
    PostOrder post_end () const;
	
protected:
    Btn<generic> * m_root;                       //<-- Holds root pointer of tree
    unsigned int m_size;                         //<-- Holds size of tree
    Btn<generic> * push;                         //<-- Holds location of next item push
	Btn<generic> * pop;                          //<-- Holds location of next item pop
};

#include "bt.hpp"
#endif
