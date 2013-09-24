////////////////////////////////////////////////////////////////////// 
/// @file test_avl.cpp
/// @author Maximilian Schroeder
/// @brief Implementation of the header file test_avl.h 
//////////////////////////////////////////////////////////////////////
#include "test_avl.h"
#include <iostream>
#include <time.h>
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION (Test_Avl);

////////////////////////////////////////////////////////////////////// 
/// @fn test_insert () 
/// @brief Tests for proper functionality of the insert function in 
/// the Bst, BT, and Avl classes
/// @pre (none)
/// @post (none) 
/// @return void 
////////////////////////////////////////////////////////////////////// 
void Test_Avl::test_insert ()
{	
	const int items = 17;
	int stuff[] = {17,15,3,5,7,19,26,32,38,41,16,24,18,11,39,2,37};
	int poststuff[] = {2,3,11,7,5,16,18,17,15,24,26,37,38,41,39,32,19};
	
	cout << endl << "test_insert()" << endl;
	cout << "===============" << endl << endl;
	
	Avl<int> a;
	Bst<int>::PostOrder post;
	int i;
	
	//insert items into Avl tree
	cerr << "Checking insert()..." ;
	
	for(i = 0; i < items; i++)
	{
		a.insert(stuff[i]);
	}
	
	//checking for proper tree structure
	
	for(post = a.post_begin(), i = 0; post != a.post_end(); post++, i++)
	{
		CPPUNIT_ASSERT (*(post.current() -> data) == poststuff[i]);
	}
	post = a.post_end();
	
	CPPUNIT_ASSERT (*(post.current() -> data) == poststuff[items - 1]);
	
	cerr << "OK" << endl;
}

////////////////////////////////////////////////////////////////////// 
/// @fn test_remove () 
/// @brief Tests for proper functionality of the remove function in 
/// the Bst, BT, and Avl classes
/// @pre (none)
/// @post (none) 
/// @return void 
//////////////////////////////////////////////////////////////////////
void Test_Avl::test_remove ()
{
	const int items = 12;
	int stuff[] = {16,8,24,4,12,18,32,10,20,28,36,26};
	int poststuff[] = {4,12,10,20,18,16,26,28,36,32,24};
	int lastremove[11];
	
	cout << endl << "test_remove()" << endl;
	cout << "===============" << endl << endl;
	
	Avl<int> a;
	Bst<int>::PostOrder post;
	Bst<int>::PreOrder pre;
	int i;
	
	//insert items into Avl tree
	
	for(i = 0; i < items; i++)
	{		
		a.insert(stuff[i]);
	}
	
	cerr << "Checking remove()..." ;
	
	//remove a node to force a double rotation
	
	a.remove(8);
	
	for(post = a.post_begin(), i = 0; post != a.post_end(); post++, i++)
	{
		CPPUNIT_ASSERT (*(post.current() -> data) == poststuff[i]);
	}
	post = a.post_end();	
	CPPUNIT_ASSERT (*(post.current() -> data) == poststuff[items - 2]);
	
	//remove remaining nodes from Avl tree
	for(i = 0; i < 11; i++)
	{
		lastremove[i] = poststuff[i];
	}
	for(i = 0; i < 11; i++)
	{
		int y = rand()%11;
		int temp = lastremove[y];
		lastremove[y] = lastremove[i];
		lastremove[i] = temp;
	}
	for(i = 0; i < 11; i++)
	{
		a.remove(lastremove[i]);
	}
	CPPUNIT_ASSERT(a.empty() == true);
	
	cout << "OK" << endl;	
}
