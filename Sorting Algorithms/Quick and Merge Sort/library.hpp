////////////////////////////////////////////////////////////////////// 
/// @file library.hpp
/// @author Maximilian Schroeder
/// @brief Implementation for the header file library.h 
//////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn int search (Vector<generic> & v, generic x) 
/// @brief Returns the index of the position in the Vector where x was
/// found
/// @pre x exists within the Vector
/// @post (none)
/// @return Index of location of x in v
////////////////////////////////////////////////////////////////////// 
unsigned int search (Vector<generic> & v, generic x)
{
	if(v.size() == 0)
	{
		throw Exception
		(
			CONTAINER_EMPTY,
			"Vector is empty. Search call failed."
		);
	}
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i] == x)
		{
			return i;
		}
	}
	throw Exception
	(
		ITEM_NOT_EXIST,
		"Item does not exist within Vector. Can't find nonexistent item."
	);
	return -1; ///<-- This is here to make the compiler happy. This line can never be hit.
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn int search (Vector<generic> & v, generic x) 
/// @brief Returns the index of the position in the Vector where x was
/// found (using binary search algorithm)
/// @pre x exists within the Vector
/// @post (none)
/// @return Index of location of x in v
////////////////////////////////////////////////////////////////////// 
unsigned int binary_search (Vector<generic> & v, generic x)
{
	if(v.size() == 0)
	{
		throw Exception
		(
			CONTAINER_EMPTY,
			"Vector is empty. Search call failed."
		);
	}
	int min = 0;
	int max = v.size() - 1;
	int l = (max + max) / 2;
	int numTimes = 0;
	int temp = max;
	while(temp != 0)
	{
		temp /= 2;
		numTimes++;
	}
	for(int i = 0; i < numTimes; i++)
	{
		if(v[l] > x)
		{
			max = l;
		}
		else if(v[l] < x)
		{
			min = l;
		}
		else
		{
			return l;
		}
		l = (max + max) / 2;
	}
	throw Exception
	(
		ITEM_NOT_EXIST,
		"Item does not exist within Vector. Can't find nonexistent item."
	);
	return -1; ///<-- This is here to make the compiler happy. This line can never be hit.
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn void bubble_sort (Vector<generic> & v) 
/// @brief Sorts the Vector v in ascending order using the bubble sort
/// algorithm
/// @pre (none)
/// @post (none)
/// @return void
////////////////////////////////////////////////////////////////////// 
void bubble_sort (Vector<generic> & v)
{
	if(v.size() == 0)
	{
		throw Exception
		(
			CONTAINER_EMPTY,
			"Vector is empty. Sort call failed."
		);
	}
	generic temp;
	bool swap = true;
	while(swap == true)
	{
		swap = false;
		for(int i = v.size() - 1; i > 0; i--)
		{
			if(v[i] < v[i - 1])
			{
				temp = v[i];
				v[i] = v[i - 1];
				v[i - 1] = temp;
				swap = true;
			}
		}
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn void selection_sort (Vector<generic> & v) 
/// @brief Sorts the Vector v in ascending order using the selection
/// sort algorithm
/// @pre (none)
/// @post (none)
/// @return void
////////////////////////////////////////////////////////////////////// 
void selection_sort (Vector<generic> & v)
{
	if(v.size() == 0)
	{
		throw Exception
		(
			CONTAINER_EMPTY,
			"Vector is empty. Sort call failed."
		);
	}
	generic temp;
	for(int i = 0; i < v.size() - 1; i++)
	{
		temp = v[i];
		for(int k = i + 1; k < v.size(); k++)
		{
			if(v[k] < temp)
			{
				temp = v[k];
			}
		}
		v[i] = temp;
	}	
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn void insertion_sort (Vector<generic> & v) 
/// @brief Sorts the Vector v in ascending order using the insertion
/// sort algorithm
/// @pre (none)
/// @post (none)
/// @return void
////////////////////////////////////////////////////////////////////// 
void insertion_sort (Vector<generic> & v)
{
	if(v.size() == 0)
	{
		throw Exception
		(
			CONTAINER_EMPTY,
			"Vector is empty. Sort call failed."
		);
	}
	generic temp;
	for(int i = 1; i <= v.size(); i++)
	{
		for(int k = 0; k < i; k++)
		{
			if(k != 0)
			{
				if(v[k] < v[k - 1])
				{
					for(int a = k; a > 0; a--)
					{
						if(v[a] < v[a - 1])
						{
							temp = v[a];
							v[a] = v[a - 1];
							v[a - 1] = temp;
						}
					}
				}
			}
		}
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn void insertion_sort (Vector<generic> & v) 
/// @brief Sorts the Vector v in ascending order using the QuickSort
/// algorithm
/// @pre (none)
/// @post (none)
/// @return void
////////////////////////////////////////////////////////////////////// 
void quick_sort (Vector<generic> & v)
{
	Stack<int> f;
	Stack<int> l;
	int pivot, ftemp, ltemp;
	generic check, temp;
	int firstGreater;
	int firstLess;
	bool first = false;
	bool second = false;
	f.push(0);
	l.push(v.size() - 1);
	while(!f.empty() && !l.empty())
	{		
		firstGreater = -1;
		firstLess = -1;
		first = false;
		second = false;
		check = v[f.top()];		
		for(int i = f.top() + 1; i <= l.top(); i++)
		{
			if(!first && v[i] > check)
			{
				firstGreater = i;
				first = true;
			}
			else if(first && !second && v[i] < check)
			{
				firstLess = i;
				second = true;
				break;
			}
		}
		if(first && second)
		{
			temp = v[firstGreater];
			v[firstGreater] = v[firstLess];
			v[firstLess] = temp;
		}
		else if(first && !second)
		{
			pivot = firstGreater - 1;
			ftemp = f.top();
			ltemp = l.top();
			if(v[pivot] == check)
			{
				f.pop();
				l.pop();
				f.push(pivot + 1);
				l.push(ltemp);
			}
			else
			{
				temp = v[f.top()];
				v[f.top()] = v[pivot];
				v[pivot] = temp;
				ftemp = f.top();
				ltemp = l.top();
				f.pop();
				l.pop();
				f.push(ftemp);
				l.push(pivot - 1);
				f.push(pivot + 1);
				l.push(ltemp);
			}
		}
		else if(!first && !second)
		{
			if(f.top() == l.top())
			{
				f.pop();
				l.pop();
			}
			else
			{
				temp = v[l.top()];
				v[l.top()] = v[f.top()];
				v[f.top()] = temp;
				ftemp = f.top();
				ltemp = l.top() - 1;
				f.pop();
				l.pop();
				f.push(ftemp);
				l.push(ltemp);
			}
		}
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn void insertion_sort (Vector<generic> & v) 
/// @brief Sorts the Vector v in ascending order using the MergeSort
/// algorithm
/// @pre (none)
/// @post (none)
/// @return void
////////////////////////////////////////////////////////////////////// 
void merge_sort (Vector<generic> & v)
{
	Stack<int> sf;
	Stack<int> sl;
	Stack<int> mf;
	Stack<int> ml;
	int f = 0;
	int l = v.size() - 1;
	generic temp;
	sf.push(f);
	sl.push(l);
	while(!sf.empty() && !sl.empty())
	{
		f = sf.top();
		l = sl.top();
		sf.pop();
		sl.pop();
		if(l - f > 0)
		{
			mf.push(f);
			ml.push(l);
			sf.push(f);
			sl.push(((l - f) / 2) + f);
			sf.push(((l - f) / 2) + f + 1);
			sl.push(l);
		}
	}
	while(!mf.empty() && !ml.empty())
	{
		f = mf.top();
		l = ml.top();
		for(int i = f; i <= l; i++)
		{
			temp = v[f];
			for(int k = i; k <= l; k++)
			{
				if(temp > v[k])
				{
					temp = v[k];
				}
			}
			v[i] = temp;
		}
		mf.pop();
		ml.pop();
	}
}
