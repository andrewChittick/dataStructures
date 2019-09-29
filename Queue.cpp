// Honor Pledge:
//
//  I pledge that I have neither given nor received any help
//  on this assignment
//  Andrew Chittick 9/28/18

/**
 * @class Queue
 *
 * Basic queue for arbitrary elements.
 */

#include "Queue.h"

// Default constructor
template <typename T>
Queue <T>::Queue (void):
	arr_ (DEFAULT_SIZE),
	front_ (0),
	back_ (0)
{}

// Copy constructor
template <typename T>
Queue <T>::Queue (const Queue & queue):
	arr_ (queue.arr_),
	front_ (queue.front_),
	back_ (queue.back_)
{}

// Destructor
template <typename T>
Queue <T>::~Queue (void)
{
	this->front_ = 0;
	this->back_ = 0;
}

/**
 * Assignment operator
 *
 * @param[in]      rhs           Right-hand side of operator
 * @return         Reference to self
 */
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
	//check for self assignment
	if (this == &rhs){
		return (*this);
	}
	//make the container the right size
	if (this->arr_.size() != rhs.arr_.size()){
		this->arr_.resize(rhs.arr_.size());
		this->arr_.shrink();
	}
	//copy the data
	for (int i = 0; i < rhs.arr_.size(); i++){
		this->arr_.set(i, rhs.arr_.get(i));
	}
	this->front_ = rhs.front_;
	this->back_ = rhs.back_;
	return (*this);
}

/**
 * Enqueue a new \a element onto the queue. The element is inserted
 * before all the other elements in the list.
 *
 * @param[in]      element       Element to add to the list
 */
template <typename T>
void Queue <T>::enqueue (T element)
{
  // COMMENT You are resizing the queue, but you are wasting space at the front of
  // the array. Fix your design so you use all the space in the array.
  //
  // I fixed this by adding a truncFront method to Array.cpp that truncates the 
  // front of an array, then calling this method if the front of the queue is 
  // greater than the default size of the array

	if (this->back_ == this->arr_.size()){
		if (this->front_ > DEFAULT_SIZE){
			//reclaim unused space at front of array
			//adjust back pointer for truncation
			this->back_ = this->back_ - this->front_;
			//truncate
			this->arr_.truncFront(this->front_);
			//adjust the front pointer
			this->front_ = 0;
		}
		//grow the array
		this->arr_.resize(this->arr_.size() * 2);
	}
	this->arr_.set(this->back_, element);
	this->back_++;
}

/**
 * Remove and return the last element from the queue.
 *
 * @exception      empty_exception    The queue is empty.
 */
template <typename T>
T Queue <T>::dequeue (void)
{
  // COMMENT You are resizing the queue, but you are wasting space at the front of
  // the array. Fix your design so you use all the space in the array.
  //
  // I fixed this by adding a truncFront method to Array.cpp that truncates the 
  // front of an array, then calling this method if the front of the queue is 
  // greater than the default size of the array when enqueueing

	if (is_empty()){
		//exception handling for empty queue
		throw empty_exception();
	}
	else{
		//pop and return
		this->front_++;
		return(arr_.get(this->front_ - 1));
	}
}

// Remove all elements from the queue
template <typename T>
void Queue <T>::clear (void)
{
	//reset the pointers
	this->front_ = 0;
	this->back_ = 0;
  
  // COMMENT There is no need to shrink the array since you
  // will just request the space later. If you want to shrink
  // the array, then you should expose a shrink() method on the
  // Queue, which delegates its call to the array.
  //
  // I fixed this by not shrinking the array anymore
}
