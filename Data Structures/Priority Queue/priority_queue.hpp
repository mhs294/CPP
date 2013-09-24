////////////////////////////////////////////////////////////////////// 
/// @file priority_queue.hpp
/// @author Maximilian Schroeder
/// @brief Implementation of the header file priority_queue.h
//////////////////////////////////////////////////////////////////////
#include <math.h>
using namespace std;

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn Priority_queue()
/// @brief Constructs a new object of type Priority_queue with 
/// m_size = 0 and m_root = NULL
/// @pre (none)
/// @post (none)
/// @return void 
////////////////////////////////////////////////////////////////////// 
Priority_queue<generic>::Priority_queue() : BT<generic> ()
{
	BT<generic>::push = NULL;
	BT<generic>::pop = NULL;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn Priority_queue(Priority_queue & a)
/// @brief Constructs a new object of type Priority_queue that is a
/// duplicate of a
/// @pre (none)
/// @post (none)
/// @return void 
//////////////////////////////////////////////////////////////////////
Priority_queue<generic>::Priority_queue(Priority_queue & a) : BT<generic> (a)
{
	set_pointers();
}

template <class generic> 
////////////////////////////////////////////////////////////////////// 
/// @fn operator= (const Priority_queue & a)
/// @brief Constructs a new object of type Priority_queue that is a
/// duplicate of a
/// @pre (none)
/// @post (none)
/// @return Priority_queue that is a duplicate of a
//////////////////////////////////////////////////////////////////////
Priority_queue<generic>& Priority_queue<generic>::operator= (const Priority_queue & a)
{
	BT<generic>::operator= (a);
    set_pointers();
	return (* this);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn push(generic x)
/// @brief Inserts an object of type generic equal to x into the 
/// priority queue at the location of the push pointer
/// @pre x is of a vaild type
/// @post (none)
/// @return void
//////////////////////////////////////////////////////////////////////
void Priority_queue<generic>::push(generic x)
{
	Btn<generic> * temp;
	if(BT<generic>::m_root != NULL)
	{
		if(BT<generic>::push -> l == NULL)
		{
			BT<generic>::push -> l = new Btn<generic>;
			temp = BT<generic>::push -> l;
			temp -> l = NULL;
			temp -> r = NULL;
			temp -> p = BT<generic>::push;
			temp -> data = new generic (x);		
		}
		else if(BT<generic>::push -> l != NULL && BT<generic>::push -> r == NULL)
		{
			BT<generic>::push -> r = new Btn<generic>;
			temp = BT<generic>::push -> r;
			temp -> l = NULL;
			temp -> r = NULL;
			temp -> p = BT<generic>::push;
			temp -> data = new generic (x);	
		}
		heapify_push(temp);
		BT<generic>::m_size++;
		set_pointers();
	}
	else
	{
		temp = BT<generic>::m_root;
		temp = new Btn<generic>;
		temp -> l = NULL;
		temp -> r = NULL;
		temp -> p = NULL;
		temp -> data = new generic (x);	
		BT<generic>::m_root = temp;
		BT<generic>::push = BT<generic>::m_root;
		BT<generic>::pop = BT<generic>::m_root;
		BT<generic>::m_size++;
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn pop()
/// @brief Removes an object from the priority queue at the location
/// of the pop pointer
/// @pre (none)
/// @post (none)
/// @return void
//////////////////////////////////////////////////////////////////////
void Priority_queue<generic>::pop()
{
	Btn<generic> * temp;
	generic * tempData;
	if(BT<generic>::m_root == NULL)
	{
		throw Exception
		(
			ITEM_NOT_EXIST,
			"Priority queue is empty. Cannot pop nonexistent item."
		);
	}
	if(BT<generic>::m_size == 1)
	{
		delete BT<generic>::m_root -> data;
		delete BT<generic>::m_root;
		BT<generic>::m_root = NULL;
		BT<generic>::push = NULL;
		BT<generic>::pop = NULL;
		BT<generic>::m_size--;
	}
	else
	{
		if(BT<generic>::pop -> r != NULL)
		{
			temp = BT<generic>::pop -> r;
			tempData = temp -> data;
			temp -> data = BT<generic>::m_root -> data;
			BT<generic>::m_root -> data = tempData;
			BT<generic>::pop -> r = NULL;
		}
		else if(BT<generic>::pop -> r == NULL && BT<generic>::pop -> l != NULL)
		{
			temp = BT<generic>::pop -> l;
			tempData = temp -> data;
			temp -> data = BT<generic>::m_root -> data;
			BT<generic>::m_root -> data = tempData;
			BT<generic>::pop -> l = NULL;
		}
		delete temp -> data;
		delete temp;
		temp = NULL;
		heapify_pop();
		BT<generic>::m_size--;
		set_pointers();
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn top()
/// @brief Returns the data contained in the node at the top of the
/// priority queue
/// @pre (none)
/// @post (none)
/// @return Data contained in the node at the top of the priority 
/// queue
//////////////////////////////////////////////////////////////////////
generic& Priority_queue<generic>::top()
{
	if(BT<generic>::m_root == NULL)
	{
		throw Exception
		(
			ITEM_NOT_EXIST,
			"There is nothing in the priority queue. Can't return nonexistent item."
		);
	}
	return *(BT<generic>::m_root -> data);
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn heapify_push(Btn<generic> * temp)
/// @brief Heapifies the data in the priority queue after an item has
/// been pushed into the priority queue
/// @pre (none)
/// @post (none)
/// @return void
//////////////////////////////////////////////////////////////////////
void Priority_queue<generic>::heapify_push(Btn<generic> * temp)
{
	generic * tempData;
	while(temp -> p != NULL)
	{
		if(*(temp -> data) > *(temp -> p -> data))
		{
			tempData = temp -> data;
			temp -> data = temp -> p -> data;
			temp -> p -> data = tempData;
			temp = temp -> p;
		}
		else
		{
			break;
		}
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn heapify_pop()
/// @brief Heapifies the data in the priority queue after an item has
/// been popped from the priority queue
/// @pre (none)
/// @post (none)
/// @return void
//////////////////////////////////////////////////////////////////////
void Priority_queue<generic>::heapify_pop()
{
	generic * tempData;
	Btn<generic> * temp = BT<generic>::m_root;
	while(temp -> l != NULL || temp -> r != NULL)
	{
		if(temp -> l != NULL && temp -> r != NULL)
		{
			if((*(temp -> l -> data) > *(temp -> data)) || (*(temp -> r -> data) > *(temp -> data)))
			{
				if((*(temp -> l -> data) > *(temp -> data)) && (*(temp -> r -> data) <= *(temp -> data))) //only l is greater
				{
					tempData = temp -> data;
					temp -> data = temp -> l -> data;
					temp -> l -> data = tempData;
					temp = temp -> l;
				}
				else if((*(temp -> l -> data) <= *(temp -> data)) && (*(temp -> r -> data) > *(temp -> data))) //only r is greater
				{
					tempData = temp -> data;
					temp -> data = temp -> r -> data;
					temp -> r -> data = tempData;
					temp = temp -> r;
				}
				else if((*(temp -> l -> data) > *(temp -> data)) && (*(temp -> r -> data) > *(temp -> data))) //both l and r are greater
				{
					if(*(temp -> l -> data) > *(temp -> r -> data)) //l is greater than r
					{
						tempData = temp -> data;
						temp -> data = temp -> l -> data;
						temp -> l -> data = tempData;
						temp = temp -> l;
					}
					else //l is not greater than r
					{
						tempData = temp -> data;
						temp -> data = temp -> r -> data;
						temp -> r -> data = tempData;
						temp = temp -> r;
					}
				}
			}
			else
			{
				break;
			}
		}
		else if(temp -> l != NULL && temp -> r == NULL)
		{
			if(*(temp -> l -> data) > *(temp -> data))
			{
				tempData = temp -> data;
				temp -> data = temp -> l -> data;
				temp -> l -> data = tempData;
				temp = temp -> l;
			}
			else
			{
				break;
			}
		}
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn set_pointers()
/// @brief Resets the locations of the push and pop pointers after a
/// push/pop has occurred
/// @pre (none)
/// @post (none)
/// @return void
//////////////////////////////////////////////////////////////////////
void Priority_queue<generic>::set_pointers()
{
	double depth;
	int level, deep;
	depth = log(BT<generic>::m_size);
	depth /= log(2);
	double check = log(BT<generic>::m_size + 1);
	check /= log(2);
	deep = (int)depth;
	if(deep == 0)
	{
		BT<generic>::push = BT<generic>::m_root;
		BT<generic>::pop = BT<generic>::m_root;
		return;
	}
	if((int)check > deep)
	{
		deep++;
	}
	level = deep;
	Btn<generic> * temp = BT<generic>::m_root;
	for(int i = 1; i < deep; i++)
	{
		temp = temp -> l;
	}
	while(temp -> l != NULL && temp -> r != NULL)
	{
		if(temp -> p -> l == temp) // temp is left-child
		{
			temp = temp -> p -> r;
		}
		else if(temp -> p -> r == temp) // temp is right-child
		{
			while(temp -> p -> r == temp)
			{
				temp = temp -> p;
				level--;
			}
			temp = temp -> p;
			level--;
			if(temp -> r != NULL)
			{
				temp = temp -> r;
				level++;
				for(int i = level; i < deep; i++)
				{
					temp = temp -> l;
					level++;
				}
			}
		}
	}
	BT<generic>::push = temp;
	if(temp -> l == NULL && temp -> r == NULL)
	{
		BT<generic>::pop = relocate_pop(temp);
		return;
	}
	BT<generic>::pop = temp;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn relocate_pop()
/// @brief Sets the location of pop if not the same location as push
/// @pre (none)
/// @post (none)
/// @return void
//////////////////////////////////////////////////////////////////////
Btn<generic>* Priority_queue<generic>::relocate_pop(Btn<generic> * temp)
{
	Btn<generic> * leftmost;
	Btn<generic> * rightmost;
	leftmost = BT<generic>::m_root;
	rightmost = BT<generic>::m_root;
	while(leftmost -> l != NULL)
	{
		leftmost = leftmost -> l;
	}
	while(rightmost -> r -> r != NULL)
	{
		rightmost = rightmost -> r;
	}
	if(temp -> p -> r == temp)
	{
		temp = temp -> p -> l;
	}
	else if(temp -> p -> l == temp && temp != leftmost)
	{
		while(temp -> p -> l == temp)
		{
			temp = temp -> p;
		}
		temp = temp -> p -> l;
		while(temp -> r -> r != NULL)
		{
			temp = temp -> r;
		}
	}
	else if(temp -> p -> l == temp && temp == leftmost)
	{
		temp = rightmost;
	}
	return temp;
}
