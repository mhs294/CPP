////////////////////////////////////////////////////////////////////// 
/// @file test_bst.cpp
/// @author Maximilian Schroeder
/// @brief Implementation of the header file test_bst.h 
//////////////////////////////////////////////////////////////////////
#include "test_bst.h"
#include <iostream>
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION (Test_Bst);

////////////////////////////////////////////////////////////////////// 
/// @fn test_insert () 
/// @brief Tests for proper functionality of the insert function in 
/// the Bst class
/// @pre (none)
/// @post (none) 
/// @return void 
////////////////////////////////////////////////////////////////////// 
void Test_Bst::test_insert ()
{	
	const int items = 16;
	
	cout<<"test_insert()"<<endl<<"================="<<endl<<endl;
	
	Bst<int> a;
	Btn<int> * t1;
	Bst<int>::PreOrder pre;
	Bst<int>::InOrder in;
	Bst<int>::PostOrder post;
	
	int stuff[] = {64,32,16,8,4,24,28,48,40,36,44,56,96,80,88,112};
	int instuff[] = {4,8,16,24,28,32,36,40,44,48,56,64,80,88,96,112};
	int poststuff[] = {4,8,28,24,16,36,44,40,56,48,32,88,80,112,96,64};
	int temp, temp1, spot, i;
	
	//insert items in the array into the binary search tree
	cout<<"Checking p_insert()...";
	
	for(int i = 0; i < items; i++)
	{
		t1 = a.p_insert(stuff[i]);
		if(i == 0)
		{
			CPPUNIT_ASSERT (t1 == NULL); //parent of first node is NULL
		}
		else
		{
			CPPUNIT_ASSERT (t1 != NULL);
		}
	}
	
	//check for exception throw - if successful, CPPUNIT_ASSERT (false) should not be hit
	try
	{
		a.insert(16);      //<-- 16 already exists within the tree		
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{		
		CPPUNIT_ASSERT (ITEM_EXIST == e.error_code());
	}
	
	cout<<"OK"<<endl;
	
	//check iterators
	cout<<"Checking PreOrder iterator...";
	
	for(pre = a.pre_begin(), i = 0; pre != a.pre_end(); pre++, i++)
	{
		CPPUNIT_ASSERT (stuff[i] == (* pre));
	}
	pre = a.pre_end();
	CPPUNIT_ASSERT (stuff[items - 1] == (* pre));
	
	cout<<"OK"<<endl;
	
	cout<<"Checking InOrder iterator...";
	
	for(in = a.in_begin(), i = 0; in != a.in_end(); in++, i++)
	{
		CPPUNIT_ASSERT (instuff[i] == (* in));
	}
	in = a.in_end();
	CPPUNIT_ASSERT (instuff[items - 1] == (* in));
	
	cout<<"OK"<<endl;
	
	cout<<"Checking PostOrder iterator...";
	
	for(post = a.post_begin(), i = 0; post != a.post_end(); post++, i++)
	{		
		CPPUNIT_ASSERT (poststuff[i] == (* post));
	}
	post = a.post_end();	
	CPPUNIT_ASSERT (poststuff[items - 1] == (* post));
	
	cout<<"OK"<<endl;
	
	//check m_size
	cout<<"Checking size()...";
	
	CPPUNIT_ASSERT (a.size() == items);
	
	cout<<"OK"<<endl;
	
	//check that all of the items exist within the binary search tree
	cerr<<"Checking p_search()...";
	
	for(int i = 0; i < items; i++)
	{
		t1 = a.p_search(stuff[i]);		
		CPPUNIT_ASSERT (*(t1 -> data) == stuff[i]);
	}
	
	cout<<"OK"<<endl;
	
	//check that all iterators function properly
	cout<<"Checking pre_search()...";
	
	for(pre = a.pre_begin(); pre != a.pre_end(); pre++)
	{
		temp = (* pre);
		CPPUNIT_ASSERT (pre == a.pre_search(temp));
	}
	temp = * (a.pre_end());
	CPPUNIT_ASSERT ((a.pre_end()) == a.pre_search(temp));
	
	cout<<"OK"<<endl;
	
	cout<<"Checking in_search()...";
	
	for(in = a.in_begin(); in != a.in_end(); in++)
	{
		temp = (* in);
		CPPUNIT_ASSERT (in == a.in_search(temp));
	}
	temp = * (a.in_end());
	CPPUNIT_ASSERT ((a.in_end()) == a.in_search(temp));
	
	cout<<"OK"<<endl;
	
	cout<<"Checking post_search()...";
	
	for(post = a.post_begin(); post != a.post_end(); post++)
	{
		temp = (* post);
		CPPUNIT_ASSERT (post == a.post_search(temp));
	}
	temp = * (a.post_end());
	CPPUNIT_ASSERT ((a.post_end()) == a.post_search(temp));
	
	cout<<"OK"<<endl;
	
	//check copy constructor
	cout<<"Checking copy constructor...";
	
	Bst<int> b(a);
	
	CPPUNIT_ASSERT (a.size() == b.size());			
	for(pre = a.pre_begin(); pre != a.pre_end(); pre++)
	{
		temp = (* pre);		
		CPPUNIT_ASSERT ((* pre) == (* b.pre_search(temp)));
	}	
	temp = * (a.pre_end());
	CPPUNIT_ASSERT (temp == (* b.pre_search(temp)));
	
	cout<<"OK"<<endl<<endl;
}

////////////////////////////////////////////////////////////////////// 
/// @fn test_remove () 
/// @brief Tests for proper functionality of the remove function in 
/// the Bst class
/// @pre (none)
/// @post (none) 
/// @return void 
//////////////////////////////////////////////////////////////////////
void Test_Bst::test_remove ()
{
	const int items = 16;
	
	cout<<"test_remove()"<<endl<<"================="<<endl<<endl;
	
	Bst<int> a;
	Btn<int> * t1;
	int stuff[] = {64,32,16,8,4,24,28,48,40,36,44,56,96,80,88,112};
	int instuff[] = {4,8,16,24,28,32,36,40,44,48,56,64,80,88,96,112};
	int poststuff[] = {4,8,28,24,16,36,44,40,56,48,32,88,80,112,96,64};
	int temp, temp1, spot;
	
	//insert items in the array into the binary search tree
	for(int i = 0; i < items; i++)
	{
		a.insert(stuff[i]);
	}
	
	//test remove functionality
	cout<<"Checking p_remove()...";
	
	for(int i = 0; i < (items - 1); i++)
	{
		t1 = a.p_remove(poststuff[i]);
		CPPUNIT_ASSERT (t1 != NULL);
	}
	
	t1 = a.p_remove(poststuff[items - 1]);
	CPPUNIT_ASSERT (t1 == NULL); //last node should be removed at root
	CPPUNIT_ASSERT (a.empty() == true);
	
	//check for exception throw - if successful, CPPUNIT_ASSERT (false) should not be hit
	try
	{		
		t1 = a.p_search(48);      //<-- 48 was removed; it no longer exists in the tree
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
		CPPUNIT_ASSERT (ITEM_NOT_EXIST == e.error_code());
	}
	
	cout<<"OK"<<endl<<endl;
}
