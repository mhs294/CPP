////////////////////////////////////////////////////////////////////// 
/// @file stack.h 
/// @author Maximilian Schroeder
/// @brief Header file for class Stack
//////////////////////////////////////////////////////////////////////
#ifndef STACK_H
#define STACK_H

#include "slist.h"

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @class Stack
/// @brief Singly-linked list that operates on a LIFO
/// (last in, first out) basis
////////////////////////////////////////////////////////////////////// 
class Stack : public SList<generic>
{
public:
    Stack ();
    Stack (Stack &);
    ~Stack ();
    Stack & operator= (const Stack &);
    void push (generic);
    void pop ();
    generic & top ();
    unsigned int size () const;
    bool empty () const;
};

#include "stack.hpp"
#endif
