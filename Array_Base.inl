// -*- C++ -*-
// Array_Base.inl
//
// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
//
// Andrew Chittick 10/5/18

// size returns size of array
template <typename T>
inline
size_t Array_Base <T>::size (void) const
{
	return (this->cur_size_);
}

// max_size returns max size of array
template <typename T>
inline
size_t Array_Base <T>::max_size (void) const
{
	return (this->max_size_);
}
