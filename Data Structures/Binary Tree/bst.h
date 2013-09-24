////////////////////////////////////////////////////////////////////// 
/// @file bst.h 
/// @author Maximilian Schroeder
/// @brief Header file for class Bst
//////////////////////////////////////////////////////////////////////
#ifndef BST_H
#define BST_H

#include "bt.h"
#include "btn.h"
#include "exception.h"
#include "btpreorderiterator.h"
#include "btinorderiterator.h"
#include "btpostorderiterator.h"

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @class Bst
/// @brief Binary Search Tree whose nodes point to a parent, left
/// child, and right child
//////////////////////////////////////////////////////////////////////
class Bst : public BT<generic>
{
public:
    Bst ();
    ~Bst ();
    void insert (generic);
    void remove (generic);
 
	typedef BTPreorderIterator<generic> PreOrder;
    typedef BTInorderIterator<generic> InOrder;
    typedef BTPostorderIterator<generic> PostOrder;
    PreOrder pre_search (generic);
    InOrder in_search (generic);
    PostOrder post_search (generic);
	
    Btn<generic> * p_insert (generic); //returns a pointer to the parent of the inserted node
    Btn<generic> * p_remove (generic); //returns a pointer to the parent of the deleted node
    Btn<generic> * p_search (generic); //returns a pointer to the node containing the found data
};

#include "bst.hpp"
#endif
