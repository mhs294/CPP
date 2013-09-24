////////////////////////////////////////////////////////////////////// 
/// @file test_array.cpp
/// @author Maximilian Schroeder
/// @brief Implementation of the header file test_array.h 
//////////////////////////////////////////////////////////////////////
#include "test_array.h"

CPPUNIT_TEST_SUITE_REGISTRATION (Test_array);

////////////////////////////////////////////////////////////////////// 
/// @fn test_push_back () 
/// @brief Tests for proper functionality of the push_back function in
/// the Array class
/// @pre (none)
/// @post (none) 
/// @return void 
////////////////////////////////////////////////////////////////////// 
void Test_array::test_push_back ()
{
	Array<int> a;
	
	//check constructor functionality
	CPPUNIT_ASSERT (a.size () == 0);
	CPPUNIT_ASSERT (a.max_size () == 20);
	
	a.push_back(-1);
	//check push_back functionality
	CPPUNIT_ASSERT (a.size () == 1);
	CPPUNIT_ASSERT (a.max_size () == 20);
	CPPUNIT_ASSERT (a[0] == -1);	
	
	//check for exception throw - if successful, CPPUNIT_ASSERT (false) should not be hit
	try
	{
		a[1]=50;
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
		CPPUNIT_ASSERT (OUT_OF_BOUNDS == e.error_code());
	}
	
	//check push_back for remainder of array containers
	for(int i=1;i<20;i++)
	{
		a.push_back(i);
		CPPUNIT_ASSERT (a.size () == i+1);
		CPPUNIT_ASSERT (a.max_size () == 20);
		CPPUNIT_ASSERT (a[i] == i);	
	}
	
	//check for exception throw - if successful, CPPUNIT_ASSERT (false) should not be hit
	try
	{
		a.push_back(21);
		CPPUNIT_ASSERT (false);	
	}
	catch (Exception & e)
	{
		CPPUNIT_ASSERT (CONTAINER_FULL == e.error_code());
	}
}

////////////////////////////////////////////////////////////////////// 
/// @fn test_pop_back () 
/// @brief Tests for proper functionality of the pop_back function in
/// the Array class
/// @pre (none)
/// @post (none) 
/// @return void 
//////////////////////////////////////////////////////////////////////
void Test_array::test_pop_back ()
{
	Array<int> a;
	
	//check constructor functionality
	CPPUNIT_ASSERT (a.size () == 0);
	CPPUNIT_ASSERT (a.max_size () == 20);
	
	//fill array
	for(int i=0;i<20;i++)
	{
		a.push_back(i);
	}
	
	//check array sizes
	CPPUNIT_ASSERT (a.size () == 20);
	CPPUNIT_ASSERT (a.max_size () == 20);
	
	a.pop_back();
	//check pop_back functionality
	CPPUNIT_ASSERT (a.size () == 19);
	CPPUNIT_ASSERT (a.max_size () == 20);
	
	//check pop_back for remainder of array containers
	for(int i=19;i>0;i--)
	{
		a.pop_back();
		CPPUNIT_ASSERT (a.size () == i-1);
		CPPUNIT_ASSERT (a.max_size () == 20);
	}
	
	//check for exception throw - if successful, CPPUNIT_ASSERT (false) should not be hit
	try
	{
		a.pop_back();
		CPPUNIT_ASSERT (false);
	}
	catch (Exception & e)
	{
		CPPUNIT_ASSERT (CONTAINER_EMPTY == e.error_code());
	}
}
