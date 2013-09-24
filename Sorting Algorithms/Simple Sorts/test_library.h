////////////////////////////////////////////////////////////////////// 
/// @file test_library.h
/// @author Maximilian Schroeder
/// @brief Header file for class Test_library
//////////////////////////////////////////////////////////////////////
#ifndef TEST_LIBRARY_H
#define TEST_LIBRARY_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>
#include "library.h"
#include "exception.h"

////////////////////////////////////////////////////////////////////// 
/// @class Test_library
/// @brief Runs unit test for functions in library.hpp
//////////////////////////////////////////////////////////////////////
class Test_library : public CPPUNIT_NS::TestFixture
{
private:
    CPPUNIT_TEST_SUITE (Test_library);
    CPPUNIT_TEST (test_search);
    CPPUNIT_TEST (test_sort);
    CPPUNIT_TEST_SUITE_END ();
	
protected:
    void test_search ();
    void test_sort ();
};

#endif
