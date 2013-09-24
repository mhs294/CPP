////////////////////////////////////////////////////////////////////// 
/// @file test_stack.cpp
/// @author Maximilian Schroeder
/// @brief Implementation of the header file test_stack.h 
//////////////////////////////////////////////////////////////////////
#include "test_stack.h"
#include <iostream>
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION (Test_stack);

////////////////////////////////////////////////////////////////////// 
/// @fn test_push () 
/// @brief Tests for proper functionality of the push function in the 
/// Stack class
/// @pre (none)
/// @post (none) 
/// @return void 
////////////////////////////////////////////////////////////////////// 
void Test_stack::test_push ()
{
	cout << endl << "test_stack" << endl << "==========" << endl << endl;
	cout << endl << "test_push():" << endl << endl;
	int i;
	SList<int>::Iterator j;
	SList<int>::Iterator k;
	
	cout << "Testing constructor..." ;
	Stack<int> s1;
	
	//check constructor functionality
	CPPUNIT_ASSERT (s1.size() == 0);
	CPPUNIT_ASSERT (s1.empty() == true);
	
	//check for exception throw - if successful, CPPUNIT_ASSERT (false) should not be hit
	try
	{
		int q = s1.top();      //<-- There is no data in linked stack to return
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
		CPPUNIT_ASSERT (CONTAINER_EMPTY == e.error_code());
	}
	cout << "OK" << endl;
	
	cout << "Testing push()..." ;
	//push 1000 items onto stack
	for(int i=0; i<1000; i++)
	{
		s1.push(i);
		
		//check push() functionality
		CPPUNIT_ASSERT (s1.size() == i+1);		
	}
	
	//test top() functionality
	CPPUNIT_ASSERT (s1.top() == 999);
	
	//traverse stack and check values in containers
	for(i = 999, j = s1.begin(); j != s1.end(); i--, j++)
	{
		CPPUNIT_ASSERT (i == * j);
	}
	cout << "OK" << endl;
	
	cout << "Testing empty(), stack is not empty..." ;
	CPPUNIT_ASSERT (s1.empty() == false);
	cout << "OK" << endl;
	
	cout << "Testing copy constructor..." ;
	Stack<int> s2 (s1);
	
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
/// Stack class
/// @pre (none)
/// @post (none) 
/// @return void 
//////////////////////////////////////////////////////////////////////
void Test_stack::test_pop ()
{
	cout << endl << "test_pop():" << endl << endl;
	Stack<int> s1;
	for(int i=0; i<1000; i++)
	{
		s1.push(i);
	}
	
	cout << "Testing pop()..." ;
	s1.pop();
	
	//check pop() functionality
	CPPUNIT_ASSERT (s1.size() == 999);
	CPPUNIT_ASSERT (s1.top() == 998);
	CPPUNIT_ASSERT (s1.empty() == false);
	
	//test pop() for remainder of stack
	for(int i = 998; i >= 0; i--)
	{
		CPPUNIT_ASSERT (i == s1.top());
		s1.pop();		
	}
	cout << "OK" << endl;
	
	cout << "Testing empty(), stack is empty..." ;
	CPPUNIT_ASSERT (s1.empty() == true);
	cout << "OK" << endl;
}
