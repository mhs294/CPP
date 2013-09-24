////////////////////////////////////////////////////////////////////// 
/// @file queue.h 
/// @author Maximilian Schroeder
/// @brief Header file for class Queue
//////////////////////////////////////////////////////////////////////
#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @class Queue
/// @brief Doubly-linked list that operates on a FIFO 
/// (first in, first out) basis
////////////////////////////////////////////////////////////////////// 
class Queue : public List<generic>
{
public:
    Queue ();
    Queue (Queue &);
    ~Queue ();
    Queue & operator= (const Queue &);
    bool empty () const;
    unsigned int size () const;
    generic & front ();
    generic & back ();
    void push (generic);
    void pop ();
};

#include "queue.hpp"
#endif
