////////////////////////////////////////////////////////////////////// 
/// @file test_slist.h 
/// @author Maximilian Schroeder
/// @brief Header file for class SList
//////////////////////////////////////////////////////////////////////
#ifndef TEST_SLIST_H
#define TEST_SLIST_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>
#include "slist.h"
#include "exception.h"

////////////////////////////////////////////////////////////////////// 
/// @class Test_slist
/// @brief Runs unit test for functions of class SList
//////////////////////////////////////////////////////////////////////
class Test_slist : public CPPUNIT_NS::TestFixture
{
private:
    CPPUNIT_TEST_SUITE (Test_slist);
    CPPUNIT_TEST (test_push_front);
    CPPUNIT_TEST (test_pop_front);
    CPPUNIT_TEST_SUITE_END ();
	
protected:
    void test_push_front ();
    void test_pop_front ();
};

#endif
