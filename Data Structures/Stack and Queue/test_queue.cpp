////////////////////////////////////////////////////////////////////// 
/// @file test_queue.cpp
/// @author Maximilian Schroeder
/// @brief Implementation of the header file test_queue.h 
//////////////////////////////////////////////////////////////////////
#include "test_queue.h"
#include <iostream>
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION (Test_queue);

////////////////////////////////////////////////////////////////////// 
/// @fn test_push () 
/// @brief Tests for proper functionality of the push function in the 
/// Queue class
/// @pre (none)
/// @post (none) 
/// @return void 
////////////////////////////////////////////////////////////////////// 
void Test_queue::test_push ()
{
	cout << endl << "test_queue" << endl << "==========" << endl << endl;
	cout << endl << "test_push():" << endl << endl;
	int i;
	List<int>::Iterator j;
	List<int>::Iterator k;
	
	cout << "Testing constructor..." ;
	Queue<int> s1;
	
	//check constructor functionality
	CPPUNIT_ASSERT (s1.size() == 0);
	CPPUNIT_ASSERT (s1.empty() == true);
	
	//check for exception throw - if successful, CPPUNIT_ASSERT (false) should not be hit
	try
	{
		int q = s1.front();      //<-- There is no data in linked queue to return
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
		CPPUNIT_ASSERT (CONTAINER_EMPTY == e.error_code());
	}
	try
	{
		int q = s1.back();      //<-- There is no data in linked queue to return
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
		CPPUNIT_ASSERT (CONTAINER_EMPTY == e.error_code());
	}
	cout << "OK" << endl;
	
	cout << "Testing push()..." ;
	//push 1000 items onto queue
	for(int i=0; i<1000; i++)
	{
		s1.push(i);
		
		//check push() functionality
		CPPUNIT_ASSERT (s1.size() == i+1);		
	}
	
	//test front() functionality
	CPPUNIT_ASSERT (s1.front() == 0);
	
	//test back() functionality
	CPPUNIT_ASSERT (s1.back() == 999);
	
	//traverse queue and check values in containers
	for(i = 0, j = s1.begin(); j != s1.end(); i++, j++)
	{
		CPPUNIT_ASSERT (i == * j);
	}
	cout << "OK" << endl;
	
	cout << "Testing empty(), queue is not empty..." ;
	CPPUNIT_ASSERT (s1.empty() == false);
	cout << "OK" << endl;
	
	cout << "Testing copy constructor..." ;
	Queue<int> s2 (s1);
	
	//check copy constructor functionality
	CPPUNIT_ASSERT (s2.size() == s1.size());
	for(j = s2.begin(), k = s1.begin(); j != s2.end(); j++, k++)
	{
		CPPUNIT_ASSERT (* j == * k);
	}
	cout << "OK" << endl;
}

////////////////////////////////////////////////////////////////////// 
/// @fn test_pop () 
/// @brief Tests for proper functionality of the pop function in the 
/// Queue class
/// @pre (none)
/// @post (none) 
/// @return void 
//////////////////////////////////////////////////////////////////////
void Test_queue::test_pop ()
{
	cout << endl << "test_pop():" << endl << endl;
	Queue<int> s1;
	for(int i=0; i<1000; i++)
	{
		s1.push(i);
	}
	
	cout << "Testing pop()..." ;
	s1.pop();
	
	//check pop() functionality
	CPPUNIT_ASSERT (s1.size() == 999);
	CPPUNIT_ASSERT (s1.front() == 1);
	CPPUNIT_ASSERT (s1.back() == 999);
	CPPUNIT_ASSERT (s1.empty() == false);
	
	//test pop() for remainder of queue
	for(int i = 1; i <= 999; i++)
	{
		CPPUNIT_ASSERT (i == s1.front());
		s1.pop();		
	}
	cout << "OK" << endl;
	
	cout << "Testing empty(), queue is empty..." ;
	CPPUNIT_ASSERT (s1.empty() == true);
	cout << "OK" << endl;
}
