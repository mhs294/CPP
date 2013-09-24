////////////////////////////////////////////////////////////////////// 
/// @file test_vector.h
/// @author Maximilian Schroeder
/// @brief Header file for class Test_vector
//////////////////////////////////////////////////////////////////////
#ifndef TEST_VECTOR_H
#define TEST_VECTOR_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>
#include "vector.h"
#include "exception.h"

////////////////////////////////////////////////////////////////////// 
/// @class Test_vector
/// @brief Runs unit test for functions of class Vector
//////////////////////////////////////////////////////////////////////
class Test_vector : public CPPUNIT_NS::TestFixture
{
  private:
    CPPUNIT_TEST_SUITE (Test_vector);
    CPPUNIT_TEST (test_push_back);
    CPPUNIT_TEST (test_pop_back);
    CPPUNIT_TEST_SUITE_END ();

  protected:
    void test_push_back ();
    void test_pop_back ();
};

#endif


