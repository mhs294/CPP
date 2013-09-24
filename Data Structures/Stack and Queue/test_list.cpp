////////////////////////////////////////////////////////////////////// 
/// @file test_list.cpp
/// @author Maximilian Schroeder
/// @brief Implementation of the header file test_list.h 
//////////////////////////////////////////////////////////////////////
#include "test_list.h"
#include <iostream>
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION (Test_list);

////////////////////////////////////////////////////////////////////// 
/// @fn test_push() 
/// @brief Tests for proper functionality of the push_front and 
/// push_back functions in the List class
/// @pre (none)
/// @post (none) 
/// @return void 
////////////////////////////////////////////////////////////////////// 
void Test_list::test_push ()
{
	cout << endl << "test_list" << endl << "=========" << endl << endl;
	cout << endl << "test_push():" << endl << endl;
	int i;
	List<int>::Iterator j;
	List<int>::Iterator k;
	
	cout << "Testing constructor..." ;
	List<int> s1;	
	
	//check constructor functionality
	CPPUNIT_ASSERT (s1.size() == 0);
	CPPUNIT_ASSERT (s1.empty() == true);
	
	//check for exception throw - if successful, CPPUNIT_ASSERT (false) should not be hit
	try
	{
		int q = s1.front();      //<-- There is no data in linked list to return
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
		CPPUNIT_ASSERT (CONTAINER_EMPTY == e.error_code());
	}
	try
	{
		int q = s1.back();      //<-- There is no data in linked list to return
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
		CPPUNIT_ASSERT (CONTAINER_EMPTY == e.error_code());
	}
	cout << "OK" << endl;
	
	cout << "Testing push_front()..." ;
	
	//push 1000 items onto front of list
	for(int i = 0 ; i < 1000; i++)
	{
		s1.push_front(i);
		
		//check push_front() functionality
		CPPUNIT_ASSERT (s1.front() == i );
		CPPUNIT_ASSERT (s1.back() == 0 );
		CPPUNIT_ASSERT (s1.size() == i+1);		
	}	
	
	//test front() functionality
	CPPUNIT_ASSERT (s1.front() == 999);
	
	//traverse list and check values in containers
	for(i = 999, j = s1.begin(); j != s1.end(); i--, j++)
	{
		CPPUNIT_ASSERT (i == * j);
	}
	cout << "OK" << endl;
	
	cout << "Testing Iterator operator ++..." ;
	
	//if program makes it this far, Iterator must have worked as used above (line 70)
	
	cout << "OK" << endl;
	
	cout << "Testing empty(), list is not empty..." ;
	CPPUNIT_ASSERT (s1.empty() == false);
	cout << "OK" << endl;
	
	cout << "Testing copy constructor..." ;	
	List<int> s2 (s1);
	
	//check copy constructor functionality
	CPPUNIT_ASSERT (s2.size() == s1.size());
	for(j = s2.begin(), k = s1.begin(); j != s2.end(); j++, k++)
	{
		CPPUNIT_ASSERT (* j == * k);
	}
	cout << "OK" << endl;
	
	cout << "Testing remove(), item at front of list..." ;
	//test remove() functionality
	s1.remove(999);
	cout << "OK" << endl;
	
	cout << "Testing remove(), item buried within list..." ;
	//test remainder of remove() functionality

	s1.remove(314);
	for(j = s1.begin(); j != s1.end(); j++)
	{
		if(* j == 314)
		{
			CPPUNIT_ASSERT (false); //<-- If 314 is found, remove failed to work
		}
	}
	
	//check for exception throw - if successful, CPPUNIT_ASSERT (false) should not be hit
	try
	{
		s1.remove(314);          //<-- 314 should not exist within list
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
		CPPUNIT_ASSERT (ITEM_NOT_EXIST == e.error_code());
	}	
	cout << "OK" << endl;
	
	cout << "Testing clear()..." ;
	//test clear() functionality
	s1.clear();
	CPPUNIT_ASSERT (s1.size() == 0);
	CPPUNIT_ASSERT (s1.empty() == true);
	cout << "OK" << endl;
	
	cout << "Testing push_back()..." ;
	//push 1000 items onto back of list
	for(int i=0; i<1000; i++)
	{
		s1.push_back(i);
		
		//check push_back() functionality
		CPPUNIT_ASSERT (s1.size() == i+1);		
	}
	
	//test back() functionality
	CPPUNIT_ASSERT (s1.back() == 999);
	
	//traverse list and check values in containers
	for(i = 0, j = s1.begin(); j != s1.end(); i++, j++)
	{
		CPPUNIT_ASSERT (i == * j);
	}
	cout << "OK" << endl;	
	
	cout << "Testing Iterator operator --..." ;
	
	//traverse list and check values in containers
	for(i = 999, j = s1.end(); j != s1.begin(); i--, j--)
	{
		CPPUNIT_ASSERT (i == * j);
	}
	cout << "OK" << endl;	
}

////////////////////////////////////////////////////////////////////// 
/// @fn test_pop () 
/// @brief Tests for proper functionality of the pop_front and
/// pop_back functions in the List class
/// @pre (none)
/// @post (none) 
/// @return void 
//////////////////////////////////////////////////////////////////////
void Test_list::test_pop ()
{
	cout << endl << "test_pop():" << endl << endl;
	List<int> s1;
	for(int i=0; i<1000; i++)
	{
		s1.push_front(i);
	}
	
	cout << "Testing pop_front()..." ;
	s1.pop_front();
	
	//check pop_front() functionality
	CPPUNIT_ASSERT (s1.size() == 999);
	CPPUNIT_ASSERT (s1.front() == 998);
	CPPUNIT_ASSERT (s1.empty() == false);
	
	//test pop_front() for remainder of list
	for(int i = 998; i>=0; i--)
	{
		CPPUNIT_ASSERT (i == s1.front());
		s1.pop_front();		
	}
	cout << "OK" << endl;
	
	cout << "Testing empty(), list is empty..." ;
	CPPUNIT_ASSERT (s1.empty() == true);
	cout << "OK" << endl;
	
	for(int i=0; i<1000; i++)
	{
		s1.push_back(i);
	}
	
	cout << "Testing pop_back()..." ;
	s1.pop_back();
	
	//check pop_front() functionality
	CPPUNIT_ASSERT (s1.size() == 999);
	CPPUNIT_ASSERT (s1.back() == 998);
	CPPUNIT_ASSERT (s1.empty() == false);
	
	//test pop_front() for remainder of list
	for(int i = 998; i>=0; i--)
	{
		CPPUNIT_ASSERT (i == s1.back());
		s1.pop_back();		
	}
	cout << "OK" << endl;
}
