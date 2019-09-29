// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Chittick 10/5/18

/**
 * @class Fixed_Array
 *
 * Basic implementation of a fixed size array class.
 */

#include "Fixed_Array.h"

// Default constructor
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void):
	Array_Base <T> (N)
{}

/**
 * Initializing constructor. Fills the contents of the 
 * array with the specified \a fill value.
 *
 * @param[in]      fill       The file value.
 */
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill):
	Array_Base <T> (N)
{
	this->fill(fill);

}

/**
 * Copy constructor.
 *
 * @param[in]      arr        Source array
 */
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr):
	Array_Base <T> (arr)
{}

// COMMENT This method should be removed since it was part of the bad design.
//
// I fixed this by removing this method


/**
 * Assignment operation
 *
 * @param[in]       rhs      Right-hand side of equal sign 
 * @return          Reference to self
 */
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	//check for self assignment
	if (this == &rhs){
		return (*this);
	}
  
  // COMMENT You should access data_ directly to avoid the unnecessary
  // bounds check.
  //
  // I fixed this by accessing data_ directly
  
	//copy the data
	for (int i = 0; i < this->size(); i++){
		this->set(i, rhs.data_[i]);
	}
	return (*this);
}

// COMMENT This method should be removed since it was part of the bad design.
//
// I fixed this by removing this method
