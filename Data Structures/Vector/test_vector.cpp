////////////////////////////////////////////////////////////////////// 
/// @file test_vector.cpp
/// @author Maximilian Schroeder
/// @brief Implementation of the header file test_vector.h 
//////////////////////////////////////////////////////////////////////
#include "test_vector.h"

CPPUNIT_TEST_SUITE_REGISTRATION (Test_vector);

////////////////////////////////////////////////////////////////////// 
/// @fn test_push_back () 
/// @brief Tests for proper functionality of the push_back function in
/// the Vector class
/// @pre (none)
/// @post (none) 
/// @return void 
////////////////////////////////////////////////////////////////////// 
void Test_vector::test_push_back ()
{
	Vector<int> a;
	
	//check constructor functionality
	CPPUNIT_ASSERT (a.size () == 0);
	CPPUNIT_ASSERT (a.max_size () == 1);
	
	a.push_back(1);
	//check push_back functionality
	CPPUNIT_ASSERT (a.size () == 1);
	CPPUNIT_ASSERT (a.max_size () == 1);
	CPPUNIT_ASSERT (a[0] == 1);	
	
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
	
	a.push_back(2);
	//check push_back for proper increase of m_max_size
	CPPUNIT_ASSERT (a.size () == 2);
	CPPUNIT_ASSERT (a.max_size () == 2);
	CPPUNIT_ASSERT (a[1] == 2);
	
	a.push_back(3);
	//check push_back for proper increase of m_max_size
	CPPUNIT_ASSERT (a.size () == 3);
	CPPUNIT_ASSERT (a.max_size () == 4);
	CPPUNIT_ASSERT (a[2] == 3);
	
	a.push_back(4);
	//check push_back for proper increase of m_max_size
	CPPUNIT_ASSERT (a.size () == 4);
	CPPUNIT_ASSERT (a.max_size () == 4);
	CPPUNIT_ASSERT (a[3] == 4);
	
	a.push_back(5);
	//check push_back for proper increase of m_max_size
	CPPUNIT_ASSERT (a.size () == 5);
	CPPUNIT_ASSERT (a.max_size () == 8);
	CPPUNIT_ASSERT (a[4] == 5);
	
	a.push_back(6);
	//check push_back for proper increase of m_max_size
	CPPUNIT_ASSERT (a.size () == 6);
	CPPUNIT_ASSERT (a.max_size () == 8);
	CPPUNIT_ASSERT (a[5] == 6);
	
	a.push_back(7);
	//check push_back for proper increase of m_max_size
	CPPUNIT_ASSERT (a.size () == 7);
	CPPUNIT_ASSERT (a.max_size () == 8);
	CPPUNIT_ASSERT (a[6] == 7);
	
	a.push_back(8);
	//check push_back for proper increase of m_max_size
	CPPUNIT_ASSERT (a.size () == 8);
	CPPUNIT_ASSERT (a.max_size () == 8);
	CPPUNIT_ASSERT (a[7] == 8);	
}

////////////////////////////////////////////////////////////////////// 
/// @fn test_pop_back () 
/// @brief Tests for proper functionality of the pop_back function in
/// the Vector class
/// @pre (none)
/// @post (none) 
/// @return void 
//////////////////////////////////////////////////////////////////////
void Test_vector::test_pop_back ()
{
	Vector<int> a;
	
	//check constructor functionality
	CPPUNIT_ASSERT (a.size () == 0);
	CPPUNIT_ASSERT (a.max_size () == 1);
	
	//fill first 8 spots in array
	for(int i=0;i<8;i++)
	{
		a.push_back(i);
	}
	
	//check size values
	CPPUNIT_ASSERT (a.size () == 8);
	CPPUNIT_ASSERT (a.max_size () == 8);
	
	a.pop_back();
	//check pop_back functionality and max_size reduction
	CPPUNIT_ASSERT (a.size () == 7);
	CPPUNIT_ASSERT (a.max_size () == 8);
	
	a.pop_back();
	//check pop_back functionality and max_size reduction
	CPPUNIT_ASSERT (a.size () == 6);
	CPPUNIT_ASSERT (a.max_size () == 8);
	
	a.pop_back();
	//check pop_back functionality and max_size reduction
	CPPUNIT_ASSERT (a.size () == 5);
	CPPUNIT_ASSERT (a.max_size () == 8);
	
	a.pop_back();
	//check pop_back functionality and max_size reduction
	CPPUNIT_ASSERT (a.size () == 4);
	CPPUNIT_ASSERT (a.max_size () == 8);
	
	a.pop_back();
	//check pop_back functionality and max_size reduction
	CPPUNIT_ASSERT (a.size () == 3);
	CPPUNIT_ASSERT (a.max_size () == 8);
	
	a.pop_back();
	//check pop_back functionality and max_size reduction
	CPPUNIT_ASSERT (a.size () == 2);
	CPPUNIT_ASSERT (a.max_size () == 4);
	
	a.pop_back();
	//check pop_back functionality and max_size reduction
	CPPUNIT_ASSERT (a.size () == 1);
	CPPUNIT_ASSERT (a.max_size () == 2);
	
	a.pop_back();
	//check pop_back functionality and max_size reduction
	CPPUNIT_ASSERT (a.size () == 0);
	CPPUNIT_ASSERT (a.max_size () == 1);
	
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
