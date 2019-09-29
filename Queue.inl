// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.
// Andrew Chittick 9/28/18

// size returns the size of the queue
template <typename T>
inline
size_t Queue <T>::size (void) const
{
	return (this->back_ - this->front_);
}

// is_empty returns true if queue empty, false if not
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
	return (this->front_ == this->back_ ? true : false);
}
