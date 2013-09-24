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
void Test_library::test_quick ()
{
	int seed = time(0);
	srand(seed);
	const int items = 16;
	
	cout<<endl<<"test_quick()"<<endl;
	cout<<"============"<<endl<<endl;
	
	cerr<<"Checking quick_sort()...";
	
	int stuff[16];
	Vector<int> v;
	for(int i = 0; i < items; i++)
	{
		v.push_back(rand() % 99 + 1);
	}
	
	quick_sort(v);
	
	for(int i = 0; i < items - 1; i++)
	{
		CPPUNIT_ASSERT (v[i] <= v[i + 1]);
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
void Test_library::test_merge()
{
	int seed = time(0);
	srand(seed);
	const int items = 16;
	
	cout<<endl<<"test_merge()"<<endl;
	cout<<"============"<<endl<<endl;
	
	cerr<<"Checking merge_sort()...";
	
	int stuff[16];
	Vector<int> v;
	for(int i = 0; i < items; i++)
	{
		v.push_back(rand() % 99 + 1);
	}
	
	merge_sort(v);
	
	for(int i = 0; i < items - 1; i++)
	{
		CPPUNIT_ASSERT (v[i] <= v[i + 1]);
	}	
	
	cerr<<"OK"<<endl;
}
