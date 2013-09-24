////////////////////////////////////////////////////////////////////// 
/// @file test_bst.h 
/// @author Maximilian Schroeder
/// @brief Header file for class test_bst
//////////////////////////////////////////////////////////////////////
#ifndef TEST_BST_H
#define TEST_BST_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>
#include "bst.h"
#include "exception.h"

////////////////////////////////////////////////////////////////////// 
/// @class Test_bst
/// @brief Runs unit test for functions of class bst
//////////////////////////////////////////////////////////////////////
class Test_Bst : public CPPUNIT_NS::TestFixture
{
private:
    CPPUNIT_TEST_SUITE (Test_Bst);
    CPPUNIT_TEST (test_insert);
    CPPUNIT_TEST (test_remove);
    CPPUNIT_TEST_SUITE_END ();
	
protected:
    void test_insert ();
    void test_remove ();
};

#endif
