////////////////////////////////////////////////////////////////////// 
/// @file test_array.h
/// @author Maximilian Schroeder
/// @brief Header file for class Test_array
//////////////////////////////////////////////////////////////////////
#ifndef TEST_ARRAY_H
#define TEST_ARRAY_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>

#include "array.h"

////////////////////////////////////////////////////////////////////// 
/// @class Test_array
/// @brief Runs unit test for functions of class Array
//////////////////////////////////////////////////////////////////////
class Test_array : public CPPUNIT_NS::TestFixture
{
  private:
    CPPUNIT_TEST_SUITE (Test_array);
    CPPUNIT_TEST (test_push_back);
    CPPUNIT_TEST (test_pop_back);
    CPPUNIT_TEST_SUITE_END ();

  protected:
    void test_push_back ();
    void test_pop_back ();
};

#endif 
