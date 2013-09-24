////////////////////////////////////////////////////////////////////// 
/// @file test_avl.h 
/// @author Maximilian Schroeder
/// @brief Header file for class test_avl
//////////////////////////////////////////////////////////////////////
#ifndef TEST_AVL_H
#define TEST_AVL_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>
#include "avl.h"
#include "exception.h"

////////////////////////////////////////////////////////////////////// 
/// @class Test_avl
/// @brief Runs unit test for functions of class bst
//////////////////////////////////////////////////////////////////////
class Test_Avl : public CPPUNIT_NS::TestFixture
{
private:
    CPPUNIT_TEST_SUITE (Test_Avl);
    CPPUNIT_TEST (test_insert);
    CPPUNIT_TEST (test_remove);
    CPPUNIT_TEST_SUITE_END ();
	
protected:
    void test_insert ();
    void test_remove ();
};

#endif
