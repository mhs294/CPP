////////////////////////////////////////////////////////////////////// 
/// @file test_library.cpp
/// @author Maximilian Schroeder
/// @brief Implementation of the header file test_library.h 
//////////////////////////////////////////////////////////////////////
#include "test_library.h"
#include <iostream>
#include <time.h>
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION (Test_library);

////////////////////////////////////////////////////////////////////// 
/// @fn test_search () 
/// @brief Tests for proper functionality of the search functions in
/// library.hpp
/// @pre (none)
/// @post (none) 
/// @return void 
////////////////////////////////////////////////////////////////////// 
void Test_library::test_search ()
{
	int seed = time(0);
	srand(seed);
	const int items = 16;
	
	cout<<endl<<"test_search()"<<endl;
	cout<<"============="<<endl<<endl;
	
	//inserting random data into vector
	Vector<int> v;
	for(int i = 0; i < items; i++)
	{
		v.push_back(rand() % 100 + 1);
	}
	
	cerr<<"Checking search()...";
	
	int y = rand() % items;
	int check = v[y];
	
	CPPUNIT_ASSERT (search(v, check) == y);
	
	cerr<<"OK"<<endl;
	
	cerr<<"Checking binary_search()...";
	
	CPPUNIT_ASSERT (search(v, check) == y);
	
	try
	{
		check = binary_search(v, 101); ///<-- 101 will never be inserted into v
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
		CPPUNIT_ASSERT (ITEM_NOT_EXIST == e.error_code());
	}
	
	cerr<<"OK"<<endl;	
}

////////////////////////////////////////////////////////////////////// 
/// @fn test_sort () 
/// @brief Tests for proper functionality of the sort functions in
/// library.hpp
/// @pre (none)
/// @post (none) 
/// @return void 
//////////////////////////////////////////////////////////////////////
void Test_library::test_sort()
{
	int seed = time(0);
	srand(seed);
	const int items = 16;
	
	cout<<endl<<"test_sort()"<<endl;
	cout<<"============="<<endl<<endl;
	
	//inserting random data into vector
	Vector<int> v;
	for(int i = 0; i < items; i++)
	{
		v.push_back(rand() % 100 + 1);
	}
	
	//creating duplicate vectors for each sort function
	Vector<int> bubble(v);
	Vector<int> select(v);
	Vector<int> insertion(v);
	
	cerr<<"Checking bubble_sort()...";
	
	bubble_sort(bubble);
	
	for(int i = 1; i < bubble.size(); i++)
	{
		CPPUNIT_ASSERT (bubble[i] >= bubble[i - 1]);
	}
	
	cerr<<"OK"<<endl;
	
	cerr<<"Checking selection_sort()...";
	
	selection_sort(select);
	
	for(int i = 1; i < select.size(); i++)
	{
		CPPUNIT_ASSERT (select[i] >= select[i - 1]);
	}
	
	cerr<<"OK"<<endl;
	
	cerr<<"Checking insertion_sort()...";
	
	insertion_sort(insertion);
	
	for(int i = 1; i < insertion.size(); i++)
	{
		CPPUNIT_ASSERT (insertion[i] >= insertion[i - 1]);
	}
	
	cerr<<"OK"<<endl;
}
