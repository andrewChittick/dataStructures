// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.
// Andrew Chittick 9/28/18

// size returns the size of the stack
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return (this->index_);
}

// top returns top of stack
template <typename T>
inline
T Stack <T>::top (void) const
{
	return (this->is_empty() ? 0: arr_.get(this->index_ - 1));
}

// is_empty returns true if stack empty, false if not
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	return (this->index_ == 0 ? true: false);
}
