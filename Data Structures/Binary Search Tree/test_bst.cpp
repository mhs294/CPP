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
	const int items = 1000;
	
	cout<<"test_insert()"<<endl<<"================="<<endl<<endl;
	
	Bst<int> a;
	Btn<int> * t1;
	
	//create array of integers from 1 - 1000
	int stuff[items];
	int temp, spot;
	for(int i = 0; i < items; i++)
	{
		stuff[i] = (i + 1);
	}
	
	//shuffle items in the array
	for(int i = 0; i < items; i++)
	{
		spot = rand() % items;
		temp = stuff[spot];
		stuff[spot] = stuff[i];
		stuff[i] = temp;
	}
	
	//insert items in the array into the binary search tree
	cout<<"Checking insert()...";
	
	for(int i = 0; i < items; i++)
	{
		a.insert(stuff[i]);
	}
	
	//check for exception throw - if successful, CPPUNIT_ASSERT (false) should not be hit
	try
	{
		a.insert(314);      //<-- 314 already exists within the tree
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
		CPPUNIT_ASSERT (ITEM_EXIST == e.error_code());
	}
	
	cout<<"OK"<<endl;
	
	//check m_size
	cout<<"Checking size()...";
	
	CPPUNIT_ASSERT (a.size() == items);
	
	cout<<"OK"<<endl;
	
	//check that all of the items exist within the binary search tree
	cout<<"Checking search()...";
	
	for(int i = 0; i < items; i++)
	{
		t1 = a.search(stuff[i]);
		CPPUNIT_ASSERT (*(t1 -> data) == stuff[i]);
	}
	
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
	const int items = 1000;
	
	cout<<"test_remove()"<<endl<<"================="<<endl<<endl;
	
	Bst<int> a;
	Btn<int> * t1;
	
	//create array of integers from 1 - 1000
	int stuff[items];
	int temp, spot;
	for(int i = 0; i < items; i++)
	{
		stuff[i] = (i+1);
	}
	
	//shuffle items in the array
	for(int i = 0; i < items; i++)
	{
		spot = rand() % items;
		temp = stuff[spot];
		stuff[spot] = stuff[i];
		stuff[i] = temp;
	}
	
	//insert items in the array into the binary search tree
	for(int i = 0; i < items; i++)
	{
		a.insert(stuff[i]);
	}
	
	//test remove functionality
	cout<<"Checking remove()...";
	
	for(int i = 1; i <= items; i++)
	{
		a.remove(i, a.search(i));
	}
	
	//check for exception throw - if successful, CPPUNIT_ASSERT (false) should not be hit
	try
	{
		t1 = a.search(314);      //<-- 314 was removed; it no longer exists in the tree
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
		CPPUNIT_ASSERT (ITEM_NOT_EXIST == e.error_code());
	}
	
	cout<<"OK"<<endl<<endl;
}
