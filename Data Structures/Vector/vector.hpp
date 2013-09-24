////////////////////////////////////////////////////////////////////// 
/// @file vector.hpp 
/// @author Maximilian Schroeder
/// @brief Implementation for the header file vector.h
//////////////////////////////////////////////////////////////////////

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn Vector () 
/// @brief Constructs an object of type Vector of size 0 and maximum
/// size of 1
/// @pre (none)
/// @post m_size = 0, m_max_size = 1
/// @return void 
////////////////////////////////////////////////////////////////////// 
Vector<generic>::Vector () : m_size (0), m_max_size (1)
{	
	m_data = new generic[m_max_size];
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn Vector (const Vector & x) 
/// @brief Constructs an duplicate object of type Vector with size and
/// contents equal to that of x
/// @pre (none)
/// @post m_size, m_max_size = x.size(), x.max_size()
/// @return void 
////////////////////////////////////////////////////////////////////// 
Vector<generic>::Vector (const Vector<generic> & x)
{
	(* this) = x;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn ~Vector () 
/// @brief Destructor for class Vector
/// @pre (none)
/// @post (none)
/// @return void 
//////////////////////////////////////////////////////////////////////
Vector<generic>::~Vector ()
{
	delete []m_data;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator= (const Vector & x)
/// @brief Sets target Vector's size and contents equal to those of x
/// @pre (none)
/// @post (none)
/// @param x Vector to be copied onto target Vector
/// @return void 
//////////////////////////////////////////////////////////////////////
Vector<generic>& Vector<generic>::operator= (const Vector & x)
{ 
	if(m_size > 0)
	{
		delete []m_data;
	}
	m_max_size = x.max_size();
	m_size = x.size();
	m_data = new generic[m_max_size];
	for(int i=0;i<m_size;i++)
	{
		m_data[i] = x[i];
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn push_back (generic x) 
/// @brief Inserts object at nearest unoccupied spot in Vector 
/// @pre (none)
/// @post m_max_size must be doubled if vector is full, m_size must be 
/// incremented by 1
/// @param x object of type generic to be put into Vector 
/// @return void 
////////////////////////////////////////////////////////////////////// 
void Vector<generic>::push_back (generic x)
{
	if (m_size == m_max_size) 
	{ 
		generic *temp = m_data;
		m_max_size *= 2;
		m_data = new generic[m_max_size];
		for(int i=0;i<m_size;i++)
		{
			m_data[i] = temp[i];
		}
		delete []temp;
	}
	m_data[m_size++] = x;
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn pop_back () 
/// @brief Decrements m_size by 1, thus removing item at end of Vector
/// @pre m_size > 0
/// @post m_size >= 0, m_size must be decremented by 1, if m_size is
/// less than or equal to one quarter of m_max_size, m_max_size is 
/// divided by 2 (if m_size becomes 0, m_max_size is set to 1)
/// @return void
////////////////////////////////////////////////////////////////////// 
void Vector<generic>::pop_back ()
{
	if(m_size == 0)
	{
		throw Exception
		(
			CONTAINER_EMPTY,
			"Vector container is empty. Cannot pop back nonexistent item."
		);
	}
	m_size--;
	if(m_size != 0)
	{
		double m_ratio = (m_max_size / m_size);
		if(m_ratio >= 4)
		{
			m_max_size /= 2;
		}
	}
	else if(m_size == 0)
	{
		m_max_size = 1;
	}
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn clear ()
/// @brief Removes all data in the Vector container
/// @pre (none) 
/// @post m_size = 0, m_max_size = 1
/// @return void
////////////////////////////////////////////////////////////////////// 
void Vector<generic>::clear ()
{
	delete []m_data;
	m_size = 0;
	m_max_size = 1;
	m_data = new generic[m_max_size];	
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator[] (unsigned int x)
/// @brief Overloads operator [] to modify values in the Vector
/// @pre x >= 0, x < m_size
/// @post (none)
/// @param x position of value in the Vector to be 
/// modified
/// @return address of the object of type generic at position x in the 
/// Vector
////////////////////////////////////////////////////////////////////// 
generic& Vector<generic>::operator[] (unsigned int x)
{
	if(x >= m_size)
	{
		throw Exception 
		(
			OUT_OF_BOUNDS,
			"Index position does not exist within scope of Vector."
		);
	}
	return m_data[x];
}

template <class generic>
////////////////////////////////////////////////////////////////////// 
/// @fn operator[] (unsigned int x) const
/// @brief Overloads operator [] to return values in the Vector
/// @pre x >= 0, x < m_size
/// @post (none)
/// @param x position of value in the Vector to be 
/// returned
/// @return object of type generic in position x in the Vector by 
/// reference 
////////////////////////////////////////////////////////////////////// 
generic& Vector<generic>::operator[] (unsigned int x) const
{
	if(x >= m_size)
	{
		throw Exception 
		(
			OUT_OF_BOUNDS,
			"Index position does not exist within scope of Vector."
		);
	}
	return m_data[x];
}

template <class generic>
/// @fn size () const
/// @brief Returns the size of the Vector
/// @pre (none)
/// @post (none)
/// @return m_size
unsigned int Vector<generic>::size () const
{
	return m_size;
}

template <class generic>
/// @fn Max_size () const
/// @brief Returns the maximum size of the Vector
/// @pre (none)
/// @post (none)
/// @return m_max_size
unsigned int Vector<generic>::max_size () const
{
	return m_max_size;
}
