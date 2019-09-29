// -*- C++ -*-

//==============================================================================
/**
 * @file      Fixed_Array.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 * Andrew Chittick 10/5/18
 */
//==============================================================================

#ifndef _CS507_FIXED_ARRAY_H_
#define _CS507_FIXED_ARRAY_H_

#include "Array_Base.h"

/**
 * @class Fixed_Array
 *
 * Implementation of a fixed size array, i.e., one that is not
 * resizeable. It is derived from Array_Base so it can inherit of
 * the Array_Base class's methods.
 */
template <typename T, size_t N>
class Fixed_Array : public Array_Base <T>
{
public:
  /// Default constructor.
  Fixed_Array (void);

  /**
   * Copy constructor.
   *
   * @param[in]      arr        Source array
   */
  Fixed_Array (const Fixed_Array <T, N> & arr);

  /**
   * Initializing constructor. Fills the contents of the
   * array with the specified \a fill value.
   *
   * @param[in]      fill       The file value.
   */
  Fixed_Array (T fill);

  /**
   * Assignment operator
   *
   * @param[in]      rhs        Right-hand side of operator.
   */
  const Fixed_Array & operator = (const Fixed_Array <T, N> & rhs);
};

// include the source file since template class
#include "Fixed_Array.cpp"

#endif  // !defined _CS507_FIXED_ARRAY_H_
