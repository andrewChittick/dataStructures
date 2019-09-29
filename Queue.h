//==============================================================================
/**
 * @file	Queue.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 * Andrew Chittick 9/28/18
 */
//==============================================================================

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <exception>
#include "Array.h"

/**
 * @class Queue
 *
 * Basic queue for arbitrary elements.
 */
template <typename T>
class Queue
{
public:
  /// Type definition of the type.
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the stack is empty.
   */
  class empty_exception : public std::exception
  {
  public:
    /// Default constructor.
    empty_exception (void)
      : std::exception () { }
  };

  /// Default constructor.
  Queue (void);

  /// Copy constructor.
  Queue (const Queue & s);

  /// Destructor.
  ~Queue (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Queue & operator = (const Queue & rhs);

  /**
   * Enqueue a new \a element onto the queue. The element is inserted
   * before all the other elements in the list.
   *
   * @param[in]      element       Element to add to the list
   */
  void enqueue (T element);

  /**
   * Remove and return the last element from the queue.
   *
   * @exception      empty_exception    The queue is empty.
   */
  T dequeue (void);

  /**
   * Test if the queue is empty
   *
   * @retval         true          The queue is empty
   * @retval         false         The queue is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of elements on the queue
   *
   * @return         Size of the queue
   */
  size_t size (void) const;

  /// Remove all elements from the stack.
  void clear (void);

private:
  // add member variable here
  Array <T> arr_;

  // 'Pointer' to front and back of queue
  size_t front_;
  size_t back_;

};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif  // !defined _QUEUE_H_
