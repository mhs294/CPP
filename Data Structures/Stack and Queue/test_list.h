////////////////////////////////////////////////////////////////////// 
/// @file test_list.h 
/// @author Maximilian Schroeder
/// @brief Header file for class test_list
//////////////////////////////////////////////////////////////////////
#ifndef TEST_LIST_H
#define TEST_LIST_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>
#include "list.h"
#include "exception.h"

////////////////////////////////////////////////////////////////////// 
/// @class Test_list
/// @brief Runs unit test for functions of class List
//////////////////////////////////////////////////////////////////////
class Test_list : public CPPUNIT_NS::TestFixture
{
private:
    CPPUNIT_TEST_SUITE (Test_list);
    CPPUNIT_TEST (test_push);
    CPPUNIT_TEST (test_pop);
    CPPUNIT_TEST_SUITE_END ();
	
protected:
    void test_push ();
    void test_pop ();
};

#endif
