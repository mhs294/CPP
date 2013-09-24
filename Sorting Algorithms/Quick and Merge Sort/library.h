////////////////////////////////////////////////////////////////////// 
/// @file library.h 
/// @author Maximilian Schroeder
/// @brief Header file for library implementation file
//////////////////////////////////////////////////////////////////////
#ifndef LIBRARY_H
#define LIBRARY_H

#include "stack.h"
#include "exception.h"
#include "vector.h"

// returns the index of where the generic was found in the vector
template <class generic>
unsigned int search (Vector<generic> &, generic);

template <class generic>
unsigned int binary_search (Vector<generic> &, generic);

// pass in the vector that is to be sorted least to greatest
template <class generic>
void bubble_sort (Vector<generic> &);

template <class generic>
void selection_sort (Vector<generic> &);

template <class generic>
void insertion_sort (Vector<generic> &);

template <class generic>
void quick_sort (Vector<generic> &);

template <class generic>
void merge_sort (Vector<generic> &);

#include "library.hpp"
#endif
