////////////////////////////////////////////////////////////////////// 
/// @file exception.cpp 
/// @author Maximilian Schroeder 
/// @brief Implementation for the header file exception.h
//////////////////////////////////////////////////////////////////////

#include "exception.h"

////////////////////////////////////////////////////////////////////// 
/// @fn Exception (Error_Type _error_code, string _error_message) 
/// @brief Constructs an Exception with a defined Error_Type and 
/// specific error_message stored in a string
/// @pre _error_code is a defined Error_Type, _error_message is not
/// a null string
/// @post m_error_code = _error_code, m_error_message = _error_message 
/// @param _error_code Error_Type used to identify problem encountered 
/// in code 
/// @param _error_message Message displayed to user to indicate 
/// specific error in code
/// @return void 
//////////////////////////////////////////////////////////////////////
Exception::Exception (Error_Type _error_code, string _error_message)
{
    m_error_code = _error_code;
    m_error_message = _error_message;
}

////////////////////////////////////////////////////////////////////// 
/// @fn error_code () 
/// @brief Returns the Error_Type stored in m_error_code
/// @pre m_error_code is a defined Error_Type
/// @post (none) 
/// @return void 
//////////////////////////////////////////////////////////////////////
Error_Type Exception::error_code ()
{
    return m_error_code;
}

////////////////////////////////////////////////////////////////////// 
/// @fn error_message () 
/// @brief Returns the string stored in m_error_message
/// @pre m_error_message is not a null string
/// @post (none) 
/// @return void 
//////////////////////////////////////////////////////////////////////
string Exception::error_message ()
{
    return m_error_message;
}
