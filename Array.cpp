// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.
// Andrew Chittick 10/5/18

#include "Array.h"

/**
 * @class Array
 *
 * Basic implementation of a standard array class
 */

//Default constructor
template <typename T>
Array <T>::Array (void):
	Array_Base <T> ()
{}

/**
 * Initializing constructor.
 *
 * @param[in]      length        Initial size
 */
template <typename T>
Array <T>::Array (size_t length):
	Array_Base <T> (length)
{}

/**
 * Initializing constructor.
 *
 * @param[in]      length        Initial size
 * @param[in]      fill          Initial value for each element
 */
template <typename T>
Array <T>::Array (size_t length, T fill):
	Array <T> (length)
{
	this->fill(fill);
}

/**
 * Copy constructor
 *
 * @param[in]     array         The source array.
 */
template <typename T>
Array <T>::Array (const Array & array):
	Array <T> (array.cur_size_)
{
	//copy the data
	for (T *iter = array.data_, *end_iter = array.data_ +
			array.cur_size_, *dest = this->data_;
			iter != end_iter; ++ iter, ++ dest)
	{
		*dest = *iter;
	}
}

/**
 * Assignment operation
 *
 * @param[in]       rhs      Right-hand side of equal sign
 * @return          Reference to self
 */
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	//check self assignment
	if (this->data_ == rhs.data_){
	  	return (*this);
	}
	//check/make arrays have equal max sizes
	else if (this->max_size_ < rhs.cur_size_){
		//this array too small
		this->resize(rhs.cur_size_);
	}
	else if (this->max_size_ > rhs.cur_size_){
		//this array max size too big 
		this->resize(rhs.cur_size_);
		this->shrink();
	}
	//make the data the same
	for (int i = 0; i < this->cur_size_; i++){
		this->data_[i] = rhs.data_[i];
	}
	return (*this);
}

/**
 * Set a new size for the array. If \a new_size is less than the current
 * size, then the array is truncated. If \a new_size if greater then the
 * current size, then the array is made larger and the new elements are
 * not initialized to anything. If \a new_size is the same as the current
 * size, then nothing happens.
 *
 * The array's original contents are preserved regardless of whether the 
 * array's size is either increased or decreased.
 *
 * @param[in]       new_size              New size of the array
 */
template <typename T>
void Array <T>::resize (size_t new_size)
{
	//need a new array if new size is > max size
	if (this->max_size_ < new_size){
		T *iter = new T [new_size];

		//copy over data
		for (int i = 0; i < this->cur_size_; i++){
			iter[i] = this->data_[i];
		}
		//assume its identity
		this->max_size_ = new_size;
		this->cur_size_ = new_size;
		delete [] this->data_;
		this->data_ = iter;
	}
	//change current size
	this->cur_size_ = new_size;
}

/// Shrink the array to reclaim unused space.
template <typename T>
void Array <T>::shrink (void)
{
	if (this->cur_size_ < this->max_size_){
		T *iter = new T[this->cur_size_];
		for (int i = 0; i < this->cur_size_; i++){
			iter[i] = this->data_[i];
		}
		this->max_size_ = this->cur_size_;
		delete [] this->data_;
		this->data_ = iter;
	}
}

/**
 * Truncates the front of an array
 *
 * @param[in]	index		the first element to be
 * 				included in new array
 */
template <typename T>
void Array <T>::truncFront (size_t index)
{
	// avoid pointless work
	if (index != 0){
		size_t new_size = this->cur_size_ - index;
		T *temp = new T [new_size];
		//from the start index to end of array
		for (size_t thisIndex = index, tempIndex = 0; thisIndex < this->cur_size_;
		       		thisIndex++, tempIndex++){
			//copy data
			temp[tempIndex] = this->data_[thisIndex];
		}
		//adjust size
		this->max_size_ = new_size;
		this->cur_size_ = new_size;
		//out with old, in with new
		delete [] this->data_;
		this->data_ = temp;
	}
}
