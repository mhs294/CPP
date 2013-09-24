////////////////////////////////////////////////////////////////////// 
/// @file avl.hpp
/// @author Maximilian Schroeder
/// @brief Implementation of the header file avl.h
//////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn insert(generic x)
/// @brief Inserts a new node into the binary tree with data equal to
/// x and balances the tree accordingly
/// @pre x is of a valid type
/// @post (none)
/// @return void 
////////////////////////////////////////////////////////////////////// 
void Avl<generic>::insert(generic a)
{
	bool balance = false;
	unsigned int type = 0;
	Btn<generic> * temp;
	Btn<generic> * x;
	Btn<generic> * y;
	Btn<generic> * z;
	temp = Bst<generic>::p_insert (a);		
	calibrateBal();
	while(temp != NULL)
	{
		if(temp -> bal == 2)
		{
			x = temp;
			y = temp -> r;
			if(y -> bal == 1)
			{
				z = y -> r;
				type = 1;
			}
			else if(y -> bal == -1)
			{
				z = y -> l;
				type = 2;
			}
			balance = true;
			break;
		}
		else if(temp -> bal == -2)
		{
			x = temp;
			y = temp -> l;
			if(y -> bal == -1)
			{
				z = y -> l;
				type = 3;
			}
			else if(y -> bal == 1)
			{
				z = y -> r;
				type = 4;
			}
			balance = true;
			break;
		}
		temp = temp -> p;
	}
	if(balance == true)
	{
		rotate(x,y,z,type);
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn remove(generic x)
/// @brief Removes a node from the binary tree whoswe data is equal to
/// x and balances the tree accordingly
/// @pre x is of a valid type, x exists within the tree
/// @post (none)
/// @return void 
//////////////////////////////////////////////////////////////////////
void Avl<generic>::remove(generic a)
{
	bool balance = false;
	unsigned int type = 0;
	Btn<generic> * temp;
	Btn<generic> * x;
	Btn<generic> * y;
	Btn<generic> * z;
	temp = Bst<generic>::p_remove (a);
	if(BT<generic>::empty() == false)
	{
		calibrateBal();
	}
	while(temp != NULL)
	{
		if(temp -> bal == 2)
		{
			x = temp;
			y = temp -> r;
			if(y -> bal == 1)
			{
				z = y -> r;
				type = 1;
			}
			else if(y -> bal == -1)
			{
				z = y -> l;
				type = 2;
			}
			balance = true;
			break;
		}
		else if(temp -> bal == -2)
		{
			x = temp;
			y = temp -> l;
			if(y -> bal == -1)
			{
				z = y -> l;
				type = 3;
			}
			else if(y -> bal == 1)
			{
				z = y -> r;
				type = 4;
			}
			balance = true;
			break;
		}
		temp = temp -> p;
	}
	while(balance == true)
	{
		rotate(x,y,z,type);
		balance = false;
		BTPostorderIterator<generic> i;
		for(i = (* this).post_begin(); i != (* this).post_end(); i++)
		{
			if(i.current() -> bal == 2)
			{
				x = i.current();
				y = i.current() -> r;
				if(y -> bal == 1)
				{
					z = y -> r;
					type = 1;
				}
				else if(y -> bal == -1)
				{
					z = y -> l;
					type = 2;
				}
				balance = true;
				break;
			}
			else if(i.current() -> bal == -2)
			{
				x = i.current();
				y = i.current() -> l;
				if(y -> bal == -1)
				{
					z = y -> l;
					type = 3;
				}
				else if(y -> bal == 1)
				{
					z = y -> r;
					type = 4;
				}
				balance = true;
				break;
			}
		}
		if(balance == false)
		{
			i = (* this).post_end();
			if(i.current() -> bal == 2)
			{
				x = i.current();
				y = i.current() -> r;
				if(y -> bal == 1)
				{
					z = y -> r;
					type = 1;
				}
				else if(y -> bal == -1)
				{
					z = y -> l;
					type = 2;
				}
				balance = true;
			}
			else if(i.current() -> bal == -2)
			{
				x = i.current();
				y = i.current() -> l;
				if(y -> bal == -1)
				{
					z = y -> l;
					type = 3;
				}
				else if(y -> bal == 1)
				{
					z = y -> r;
					type = 4;
				}
				balance = true;
			}
		}
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn calibrateBal()
/// @brief Calibrates the balance values of each node in the binary
/// tree
/// @pre (none)
/// @post (none)
/// @return void 
//////////////////////////////////////////////////////////////////////
void Avl<generic>::calibrateBal()
{
	BTPostorderIterator<generic> i;
	for(i = (* this).post_begin(); i != (* this).post_end(); i++)
	{
		if(i.current() -> l == NULL && i.current() -> r == NULL) //node has no children
		{
			i.current() -> depth = 0;
			i.current() -> bal = 0;
		}
		else if(i.current() -> l != NULL && i.current() -> r == NULL) //node has left-child, but no right-child
		{
			i.current() -> depth = (1 + i.current() -> l -> depth);			
			i.current() -> bal = ((i.current() -> depth) * -1);
		}
		else if(i.current() -> r != NULL && i.current() -> l == NULL) //node has right-child, but no left-child
		{	
			i.current() -> depth = (1 + i.current() -> r -> depth);
			i.current() -> bal = i.current() -> depth;	
		}
		else if(i.current() -> l != NULL && i.current() -> r != NULL) //node has both left and right-child
		{
			if((i.current() -> l -> depth) > (i.current() -> r -> depth))
			{
				i.current() -> depth = (i.current() -> l -> depth) + 1;
			}
			else
			{
				i.current() -> depth = (i.current() -> r -> depth) + 1;
			}
			i.current() -> bal = ((i.current() -> r -> depth) - (i.current() -> l -> depth));
		}
	}
	i = (* this).post_end();	
	if(i.current() -> l == NULL && i.current() -> r == NULL) //node has no children
	{
		i.current() -> depth = 0;
		i.current() -> bal = 0;
	}
	else if(i.current() -> l != NULL && i.current() -> r == NULL) //node has left-child, but no right-child
	{
		i.current() -> depth = (1 + i.current() -> l -> depth);
		i.current() -> bal = ((i.current() -> depth) * -1);
	}
	else if(i.current() -> r != NULL && i.current() -> l == NULL) //node has right-child, but no left-child
	{
		i.current() -> depth = (1 + i.current() -> r -> depth);
		i.current() -> bal = i.current() -> depth;	
	}
	else if(i.current() -> l != NULL && i.current() -> r != NULL) //node has both left and right-child
	{
		if((i.current() -> l -> depth) > (i.current() -> r -> depth))
		{
			i.current() -> depth = (i.current() -> l -> depth) + 1;
		}
		else
		{
			i.current() -> depth = (i.current() -> r -> depth) + 1;
		}
		i.current() -> bal = ((i.current() -> r -> depth) - (i.current() -> l -> depth));
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn rotate(Btn<generic> * x, Btn<generic> * y, Btn<generic> * z, unsigned int type)
/// @brief Rotates the nodes in the binary tree to balance it
/// @pre (none)
/// @post (none)
/// @return void 
//////////////////////////////////////////////////////////////////////
void Avl<generic>::rotate(Btn<generic> * x, Btn<generic> * y, Btn<generic> * z, unsigned int type)
{
	switch(type) //manipulates pointers based on rotation type
	{
		case 1:
			y -> p = x -> p;
			if(x -> p != NULL)
			{
				if(x -> p -> l == x)
				{
					x -> p -> l = y;
				}
				else if(x -> p -> r == x)
				{
					x -> p -> r = y;
				}
			}
			else
			{
				BT<generic>::m_root = y;
			}
			x -> r = y -> l;
			if(y -> l != NULL)
			{
				x -> r -> p = x;
			}
			y -> l = x;
			x -> p = y;
			break;
		case 2:
			z -> p = x -> p;
			if(x -> p != NULL)
			{
				if(x -> p -> l == x)
				{
					x -> p -> l = z;
				}
				else if(x -> p -> r == x)
				{
					x -> p -> r = z;
				}
			}
			else
			{
				BT<generic>::m_root = z;
			}
			x -> r = z -> l;
			if(z -> l != NULL)
			{
				z -> l -> p = x;
			}
			y -> l = z -> r;
			if(z -> r != NULL)
			{
				z -> r -> p = y;
			}
			z -> l = x;
			z -> r = y;
			x -> p = z;
			y -> p = z;
			break;
		case 3:
			y -> p = x -> p;
			if(x -> p != NULL)
			{
				if(x -> p -> l == x)
				{
					x -> p -> l = y;
				}
				else if(x -> p -> r == x)
				{
					x -> p -> r = y;
				}
			}
			else
			{
				BT<generic>::m_root = y;
			}
			x -> l = y -> r;
			if(y -> r != NULL)
			{
				x -> l -> p = x;
			}
			y -> r = x;
			x -> p = y;
			break;
		case 4:
			z -> p = x -> p;
			if(x -> p != NULL)
			{
				if(x -> p -> l == x)
				{
					x -> p -> l = z;
				}
				else if(x -> p -> r == x)
				{
					x -> p -> r = z;
				}
			}
			else
			{
				BT<generic>::m_root = z;
			}
			x -> l = z -> r;
			if(z -> l != NULL)
			{
				z -> r -> p = x;
			}
			y -> r = z -> l;
			if(z -> r != NULL)
			{
				z -> l -> p = y;
			}
			z -> r = x;
			z -> l = y;
			x -> p = z;
			y -> p = z;
			break;
	}
	calibrateBal();
}
