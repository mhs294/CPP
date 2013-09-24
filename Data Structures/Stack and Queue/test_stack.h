////////////////////////////////////////////////////////////////////// 
/// @file test_stack.h 
/// @author Maximilian Schroeder
/// @brief Header file for class test_stack
//////////////////////////////////////////////////////////////////////
#ifndef TEST_STACK_H
#define TEST_STACK_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>
#include "stack.h"
#include "exception.h"

////////////////////////////////////////////////////////////////////// 
/// @class Test_stack
/// @brief Runs unit test for functions of class stack
//////////////////////////////////////////////////////////////////////
class Test_stack : public CPPUNIT_NS::TestFixture
{
private:
    CPPUNIT_TEST_SUITE (Test_stack);
    CPPUNIT_TEST (test_push);
    CPPUNIT_TEST (test_pop);
    CPPUNIT_TEST_SUITE_END ();
	
protected:
    void test_push ();
    void test_pop ();
};

#endif
