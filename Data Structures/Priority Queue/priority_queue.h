////////////////////////////////////////////////////////////////////// 
/// @file priority_queue.h
/// @author Maximilian Schroeder
/// @brief Header file for class Priority_queue
//////////////////////////////////////////////////////////////////////
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "bt.h"
#include "btn.h"
#include "exception.h"
template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @class Priority_queue
/// @brief Binary Search Tree which sorts data based on priority 
/// level
//////////////////////////////////////////////////////////////////////
class Priority_queue : public BT<generic>
{
public:
    Priority_queue();
    Priority_queue(Priority_queue &);
    Priority_queue & operator= (const Priority_queue &);
    void push(generic);
    void pop();
    generic & top();
	void heapify_push(Btn<generic> *);
	void heapify_pop();
	void set_pointers();
	Btn<generic>* relocate_pop(Btn<generic>*);
};

#include "priority_queue.hpp"
#endif
