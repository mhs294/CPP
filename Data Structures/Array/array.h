////////////////////////////////////////////////////////////////////// 
/// @file array.h 
/// @author Maximilian Schroeder
/// @brief Header file for class Array 
//////////////////////////////////////////////////////////////////////
#ifndef ARRAY_H
#define ARRAY_H

#include "exception.h"

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @class Array
/// @brief Protected array with set max_size of 20
////////////////////////////////////////////////////////////////////// 
class Array
{
  public:
    Array ();
    void push_back (generic);
    void pop_back ();
    void clear ();
    generic& operator[] (unsigned int);
    generic& operator[] (unsigned int) const;
    unsigned int size () const;
    unsigned int max_size () const;

  private:
    unsigned int m_size;      ///< holds current size of the array
    unsigned int m_max_size;  ///< holds maximum size of the array
    generic m_data[20];       ///< holds the values stored in the array
};

#include "array.hpp"
#endif
