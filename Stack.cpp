// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Chittick 9/28/18

#include "Stack.h"

/**
 * @class Stack
 *
 * Basic stack for abitrary elements.
 */

// Default constructor
template <typename T>
Stack <T>::Stack (void):
	arr_ (DEFAULT_SIZE),
	index_ (0)
{}

// Copy constructor
template <typename T>
Stack <T>::Stack (const Stack & stack):
	arr_(stack.arr_),
	index_ (stack.index_)
{}

// Destructor
template <typename T>
Stack <T>::~Stack (void)
{
  // COMMENT There is no need to reset the stack in the destructor since
  // the object is no longer usable when this method returns.
  //
  // I fixed this by removing the line resetting the index
}

/**
 * Assignment operator
 *
 * @param[in]      rhs           Right-hand side of operator
 * @return         Reference to self
 */
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	//check for self assignment
	if (this == &rhs){
		return (*this);
	}
	//make the container the right size
	if (this->arr_.size() != rhs.index_){
		this->arr_.resize(rhs.index_);
    
    // COMMENY Why shrink the array if you will eventually make
    // it larger as new elements are added.
    //
    // I fixed this by not shrinking the array anymore
    
	}
	//copy the data
	for (int i = 0; i < rhs.index_; i++){
		this->arr_.set(i, rhs.arr_.get(i));
	}
	this->index_ = rhs.index_;
	return (*this);
}

/**
 * Push a new \a element onto the stack. The element is inserted
 * before all the other elements in the list.
 *
 * @param[in]      element       Element to add to the list
 */
template <typename T>
void Stack <T>::push (T element)
{
	if (this->index_ == this->arr_.size()){
		//double the 'size' of the stack
		this->arr_.resize(this->arr_.size() * 2);
	}
	this->arr_.set(this->index_, element);
	this->index_++;
}

/**
 * Remove the top-most element from the stack.
 *
 * @exception      empty_exception    The stack is empty.
 */
template <typename T>
void Stack <T>::pop (void)
{
	if (is_empty()){
		//exception handling for empty stack
		throw empty_exception();
	}
	else{
		this->index_--;
	}
}

// Remove all elements from the stack
template <typename T>
void Stack <T>::clear (void)
{
	//reset the index
	this->index_ = 0;
  
  // COMMENT Is there really a benefit to reclaiming the space if the stack will
  // just grow again?!
  //
  // I fixed this by not shrinking the stack anymore
}
