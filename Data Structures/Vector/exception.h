////////////////////////////////////////////////////////////////////// 
/// @file exception.h
/// @author Maximilian Schroeder
/// @brief Header file for the Exception class
//////////////////////////////////////////////////////////////////////
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
using std::string;

enum Error_Type { CONTAINER_EMPTY, OUT_OF_BOUNDS };

////////////////////////////////////////////////////////////////////// 
/// @class Exception
/// @brief Class used to handle/display error codes thrown in a 
/// program
////////////////////////////////////////////////////////////////////// 
class Exception
{
  public:
    Exception (Error_Type, string);
    Error_Type error_code ();
    string error_message ();

  private:
    Error_Type m_error_code;  ///< Stores the defined Error_Type 
    string m_error_message;   ///< Stores the error message to be displayed
};

#endif
