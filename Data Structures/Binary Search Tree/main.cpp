////////////////////////////////////////////////////////////////////// 
/// @file main.cpp 
/// @author Maximilian Schroeder
/// @brief Driver file for the program SList_Class
//////////////////////////////////////////////////////////////////////
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

int main ()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest (registry.makeTest ());

    return runner.run ("", false);
}
