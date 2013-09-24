////////////////////////////////////////////////////////////////////// 
/// @file vector.h 
/// @author Maximilian Schroeder
/// @brief Header file for class Vector 
//////////////////////////////////////////////////////////////////////
#ifndef VECTOR_H
#define VECTOR_H

#include "exception.h"

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @class Vector
/// @brief Protected array with dynamic max_size
////////////////////////////////////////////////////////////////////// 
class Vector
{
  public:
    Vector ();
    Vector (const Vector &);
    ~Vector ();
    Vector & operator= (const Vector &);
    void push_back (generic);
    void pop_back ();
    void clear ();
    generic & operator[] (unsigned int);
    generic & operator[] (unsigned int) const;
    unsigned int size () const;
    unsigned int max_size () const;

  private:
    unsigned int m_size;      ///< holds current size of the array
    unsigned int m_max_size;  ///< holds maximum size of the array
    generic * m_data;         ///< holds the values stored in the array    
};

#include "vector.hpp"
#endif
