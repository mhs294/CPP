////////////////////////////////////////////////////////////////////// 
/// @file test_priority_queue.cpp
/// @author Maximilian Schroeder
/// @brief Implementation of the header file test_priority_queue.h 
//////////////////////////////////////////////////////////////////////
#include "test_priority_queue.h"
#include <iostream>
#include <math.h>
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION (Test_priority_queue);

////////////////////////////////////////////////////////////////////// 
/// @fn test_insert () 
/// @brief Tests for proper functionality of the push function in the
/// priority_queue class
/// @pre (none)
/// @post (none) 
/// @return void 
////////////////////////////////////////////////////////////////////// 
void Test_priority_queue::test_push ()
{	
	cout<<endl<<"test_push ()"<<endl;
	cout<<"============"<<endl<<endl;
	
	const int items = 15;
	int stuff[] = {6,18,13,22,19,25,22,19,11,27,29,31,3,1,12};
	int root[] = {6,18,18,22,22,25,25,25,25,27,29,31,31,31,31};
	
	//construct priority queue
	cerr<<"Checking constructor...";
	
	Priority_queue<int> p;
	
	CPPUNIT_ASSERT (p.size() == 0);
	
	//check for exception throw - if successful, CPPUNIT_ASSERT (false) should not be hit
	try
	{
		int test = p.top();      //<-- the priority queue is empty
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
		CPPUNIT_ASSERT (ITEM_NOT_EXIST == e.error_code());
	}
	
	cerr<<"OK"<<endl;
	
	//insert data into priority queue
	cerr<<"Checking push()...";
	
	for(int i = 0; i < items; i++)
	{
		p.push(stuff[i]);
		
		//check size of priority queue
		CPPUNIT_ASSERT (p.size() == i + 1);
		CPPUNIT_ASSERT (p.top() == root[i]);
	}
	
	cerr<<"OK"<<endl;
	
	//construct duplicate priority queue
	cerr<<"Checking copy constructor...";
	
	Priority_queue<int> p2(p);
	
	CPPUNIT_ASSERT (p2.size() == p.size());
	
	//check depth of priority queue
	double depth = log(p.size());
	depth /= log(2);
	int deep = (int)depth;
	
	CPPUNIT_ASSERT (deep == 3);
	
	cerr<<"OK"<<endl;
}

////////////////////////////////////////////////////////////////////// 
/// @fn test_remove () 
/// @brief Tests for proper functionality of the pop function in the
/// priority_queue class
/// @pre (none)
/// @post (none) 
/// @return void 
//////////////////////////////////////////////////////////////////////
void Test_priority_queue::test_pop ()
{
	cout<<endl<<"test_pop ()"<<endl;
	cout<<"============"<<endl<<endl;
	
	const int items = 15;
	int stuff[] = {6,18,13,22,19,25,22,19,11,27,29,31,3,1,12};
	int root[] = {31,29,27,25,22,22,19,19,18,13,12,11,6,3,1};
	
	Priority_queue<int> p;
	
	for(int i = 0; i < items; i++)
	{		
		p.push(stuff[i]);
	}
	
	//check pop
	cerr<<"Checking pop()...";
	
	for(int i = 0; i < items; i++)
	{
		CPPUNIT_ASSERT (p.top() = root[i]);
		
		p.pop();
		
		CPPUNIT_ASSERT (p.size() == items - i - 1);
	}
	
	//check for exception throw - if successful, CPPUNIT_ASSERT (false) should not be hit
	try
	{
		p.pop();      //<-- the priority queue is empty
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
		CPPUNIT_ASSERT (ITEM_NOT_EXIST == e.error_code());
	}
	
	cerr<<"OK"<<endl;
}
