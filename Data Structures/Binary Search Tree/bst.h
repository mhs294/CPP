////////////////////////////////////////////////////////////////////// 
/// @file bst.h 
/// @author Maximilian Schroeder
/// @brief Header file for class Bst
//////////////////////////////////////////////////////////////////////
#ifndef BST_H
#define BST_H

#include "btn.h"
#include "exception.h"
template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @class Bst
/// @brief Binary Search Tree whose nodes point to a parent, left
/// child, and right child
//////////////////////////////////////////////////////////////////////
class Bst
{
public:
    Bst ();
    ~Bst ();
    void insert (generic);
    void remove (generic, Btn<generic>*);
    Btn<generic>* search (generic);
    void clear ();
    bool empty ();
    unsigned int size ();
private:
	unsigned int m_size;    ///< holds the current size of the binary search tree
	Btn<generic> * m_root;  ///< holds the root pointer of the binary search tree
};

#include "bst.hpp"
#endif
