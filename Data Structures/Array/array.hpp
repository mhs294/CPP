////////////////////////////////////////////////////////////////////// 
/// @file array.hpp 
/// @author Maximilian Schroeder
/// @brief Implementation for the header file array.h
//////////////////////////////////////////////////////////////////////

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn Array () 
/// @brief Constructs an object of type Array of size 0 and maximum
/// size of 20
/// @pre (none)
/// @post m_size = 0, m_max_size = 20  
/// @return void 
////////////////////////////////////////////////////////////////////// 
Array<generic>::Array () : m_size (0), m_max_size (20)
{	
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn push_back (generic x) 
/// @brief Inserts object at nearest unoccupied spot in array 
/// @pre m_size < 20
/// @post m_size <= 20, m_size must be incremented by 1
/// @param x object of type generic to be put into array 
/// @return void 
////////////////////////////////////////////////////////////////////// 
void Array<generic>::push_back (generic x)
{
	if (m_size >= m_max_size) 
	{ 
		throw Exception 
		( 
			CONTAINER_FULL, 
			"Array container is full. Cannot push back another item."
		); 
	}
	m_data[m_size++] = x;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn pop_back () 
/// @brief Decrements m_size by 1, thus removing item at end of array
/// @pre m_size > 0
/// @post m_size >= 0, m_size must be decremented by 1
/// @return void
////////////////////////////////////////////////////////////////////// 
void Array<generic>::pop_back ()
{
	if(m_size == 0)
	{
		throw Exception
		(
			CONTAINER_EMPTY,
			"Array container is empty. Cannot pop back nonexistent item."
		);
	}
	m_size--;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn clear ()
/// @brief Removes all data in the array container
/// @pre (none) 
/// @post m_size = 0
/// @return void
////////////////////////////////////////////////////////////////////// 
void Array<generic>::clear ()
{
	m_size = 0;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator[] (unsigned int x)
/// @brief Overloads operator [] to modify values in the array
/// @pre x >= 0, x < m_size
/// @post (none)
/// @param x position of value in the array to be 
/// modified
/// @return address of the object of type generic at position x in the 
/// array
////////////////////////////////////////////////////////////////////// 
generic& Array<generic>::operator[] (unsigned int x)
{
	if(x >= m_size)
	{
		throw Exception 
		(
			OUT_OF_BOUNDS,
			"Index position does not exist within scope of array."
		);
	}
	return m_data[x];
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator[] (unsigned int x) const
/// @brief Overloads operator [] to return values in the array
/// @pre x >= 0, x < m_size
/// @post (none)
/// @param x position of value in the array to be 
/// returned
/// @return object of type generic in position x in the array by 
/// reference 
////////////////////////////////////////////////////////////////////// 
generic& Array<generic>::operator[] (unsigned int x) const
{
	if(x >= m_size)
	{
		throw Exception 
		(
			OUT_OF_BOUNDS,
			"Index position does not exist within scope of array."
		);
	}
	return m_data[x];
}

template <class generic>
/// @fn size () const
/// @brief Returns the size of the array
/// @pre (none)
/// @post (none)
/// @return m_size
unsigned int Array<generic>::size () const
{
	return m_size;
}

template <class generic>
/// @fn Max_size () const
/// @brief Returns the maximum size of the array
/// @pre (none)
/// @post (none)
/// @return m_max_size
unsigned int Array<generic>::max_size () const
{
	return m_max_size;
}
