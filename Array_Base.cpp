// Array_Base.cpp 

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.
// Andrew Chittick 10/5/18

/**
 * @class Array_Base
 *
 * Basic implementation of an array base class
 */

#include "Array_Base.h"

//Default constructor
template <typename T>
Array_Base <T>::Array_Base (void):
	data_ (new T [DEFAULT_SIZE]),
	max_size_ (DEFAULT_SIZE),
	cur_size_ (0)
{}

/**
 * Initializing constructor.
 *
 * @param[in]      length        Initial size
 */
template <typename T>
Array_Base <T>::Array_Base (size_t length):
	data_ (nullptr),
	max_size_ (0),
	cur_size_ (0)
{
	//don't create a useless array
	if (length == 0){
		length = DEFAULT_SIZE;
	}
	this->data_ = new T [length];
	this->max_size_ = length;
	this->cur_size_ = length;
}

/**
 * Copy constructor
 *
 * @param[in]     arr         The source array.
 */
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & array):
	Array_Base <T> (array.cur_size_)
{
	//copy the data
	for (T *iter = array.data_, *end_iter = array.data_ +
			array.cur_size_, *dest = this->data_;
			iter != end_iter; ++ iter, ++ dest)
	{
		*dest = *iter;
	}
}

// Destructor
template <typename T>
Array_Base <T>::~Array_Base (void)
{
	if (nullptr != this->data_){
		delete [] data_;
		this->cur_size_ = 0;
		this->max_size_ = 0;
	}
}

/**
 * Get the character at the specified index. If the index is not
 * within the range of the array, then std::out_of_range exception
 * is thrown.
 *
 * @param[in]       index               Zero-based location
 * @exception       std::out_of_range   Invalid \a index value
 */
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
	//handle out of range exceptions
	if (index > (cur_size_ - 1)){
		throw std::out_of_range("index out of range");
	}

	else if (this->cur_size_ == 0){
		throw std::out_of_range("index out of range");
	}
	return(this->data_[index]);
}

/**
 * @overload
 *
 * The returned character is not modifiable.
 */
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
	//handle out of range exceptions
	if (index > (cur_size_ - 1)){
		throw std::out_of_range("index out of range");
	}
	else if (this->cur_size_ == 0){
		throw std::out_of_range("index out of range");
	}
	return (this->data_[index]);
}

/**
 * Get the character at the specified index. If the \a index is not within
 * the range of the array, then std::out_of_range exception is thrown.
 *
 * @param[in]       index                 Zero-based location
 * @return          Character at \index
 * @exception       std::out_of_range     Invalid index value
 */  
template <typename T>
T Array_Base <T>::get (size_t index) const
{
	//handle out of range exceptions
	if (index > (cur_size_ - 1)){
		throw std::out_of_range("index out of range");
	}
	else if (this->cur_size_ == 0){
		throw std::out_of_range("index out of range");
	}
	return (this->data_[index]);
}

/** 
 * Set the character at the specified \a index. If the \a index is not
 * within range of the array, then std::out_of_range exception is 
 * thrown.
 *
 * @param[in]       index                 Zero-based location
 * @param[in]       value                 New value for character
 * @exception       std::out_of_range     Invalid \a index value
 */
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
	//handle out of range exceptions
	if (index > (cur_size_ - 1)){
		throw std::out_of_range("index out of range");
	}
	else if (this->cur_size_ == 0){
		throw std::out_of_range("index out of range");
	}
	this->data_[index] = value;//assign new data
}

/**
 * Locate the specified character in the array. The index of the first
 * occurrence of the character is returned. If the character is not
 * found in the array, then -1 is returned.
 *
 * @param[in]        value     Character to search for
 * @return           Index value of the character
 * @retval           -1        Character not found
 */
template  <typename T>
int Array_Base <T>::find (T value) const
{
	T *iter = this->data_;
	for (int index = 0; index < this->cur_size_; index++, iter++){
		if (*iter == value){
			return (index);
		}
	}
	return (-1);
}

/**
 * @overload
 *
 * This version allows you to specify the start index of the search. If
 * the start index is not within the range of the array, then the
 * std::out_of_range exception is thrown.
 *
 * @param[in]       ch                   Character to search for
 * @param[in]       start                Index to begin search
 * @return          Index value of first occurrence
 * @retval          -1                   Character not found
 * @exception       std::out_of_range    Invalid index
 */
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
	//handle out of range exceptions
	if (start > this->cur_size_ - 1){
		throw std::out_of_range("start index out of range");
	}
	else if (this->cur_size_ == 0){
		throw std::out_of_range("index out of range");
	}

	T *iter = (this->data_ + start);
	for (int index = 0; index < this->cur_size_; index++){
		if (*iter == val){
			return (index + start);
		}
		iter += 1;
	}
	return (-1);
}

/**
 * Test the array for equality.
 *
 * @param[in]       rhs                  Right hand side of equal to sign
 * @retval          true                 Left side is equal to right side
 * @retval          false                Left side is not equal to right side
 */
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
	if (this->data_ == rhs.data_){
		return (true);
	}
	//comare rhs to member data_ variables
	if (this->cur_size_ == rhs.cur_size_){
		//test value of every char in array
		for (int i = 0; i < cur_size_; i++){
			if (this->data_[i] != rhs.data_[i]){
				return (false);
			}
		}
		return (true);
	}
	return (false);
}

/**
 * Test the array for inequality.
 *
 * @param[in]       rhs                  Right-hand size of not equal to sign
 * @retval          true                 Left side is not equal to right side
 * @retval          false                Left size is equal to right side
 */
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
	return (!(*this == rhs));
}

/**
 * Fill the contents of the array.
 *
 * @param[in]       value                   Fill value
 */
template <typename T>
void Array_Base <T>::fill (T value)
{
	T *iter = this->data_;
	for (int i=0; i<cur_size_; i++){
		iter[i] = value;
	}
}

/// Reverse the contents of the array such that the first element is now
/// the last element and the last element is the first element.
template <typename T>
void Array_Base <T>::reverse (void)
{
	T *begin = this->data_;
	T *end = (this->data_ + cur_size_ - 1);
	T tmp;

	for (int i=0; i < (this->cur_size_/2); i++){
		tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;
	}
}
