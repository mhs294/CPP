////////////////////////////////////////////////////////////////////// 
/// @file test_priority_queue.h 
/// @author Maximilian Schroeder
/// @brief Header file for class test_priority_queue
//////////////////////////////////////////////////////////////////////
#ifndef TEST_PRIORITY_QUEUE_H
#define TEST_PRIORITY_QUEUE_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>
#include "priority_queue.h"
#include "exception.h"

////////////////////////////////////////////////////////////////////// 
/// @class Test_priority_queue
/// @brief Runs unit test for functions of class Priority_queue
//////////////////////////////////////////////////////////////////////
class Test_priority_queue : public CPPUNIT_NS::TestFixture
{
private:
    CPPUNIT_TEST_SUITE (Test_priority_queue);
    CPPUNIT_TEST (test_push);
    CPPUNIT_TEST (test_pop);
    CPPUNIT_TEST_SUITE_END ();
	
protected:
    void test_push ();
    void test_pop ();
};

#endif
