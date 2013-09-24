////////////////////////////////////////////////////////////////////// 
/// @file avl.h 
/// @author Maximilian Schroeder
/// @brief Header file for class Avl
//////////////////////////////////////////////////////////////////////
#ifndef AVL_H
#define AVL_H

#include "bst.h"

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @class Avl
/// @brief Binary Search Tree which progressively balances node 
/// distribution while inserting/removing data
//////////////////////////////////////////////////////////////////////
class Avl : public Bst<generic>
{
public:
    void insert(generic);
    void remove(generic);
	void calibrateBal();
	void rotate(Btn<generic>*, Btn<generic>*, Btn<generic>*, unsigned int);
};

#include "avl.hpp"
#endif
