// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

// Ryan: Include the honor pledge in each file.

// Fix: Included honor pledge

//
// size
//
template <typename T>
inline
size_t Base_Array <T>::size (void) const
{
	return cur_size_;
}

//
// max_size
//
template <typename T>
inline
size_t Base_Array <T>::max_size (void) const
{
	return max_size_;
}
