// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

// Ryan: Please include the honor pledge in each file.

// Fix: Included honor pledge

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void): Base_Array<T>()
{
	//use the void constructor
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length): Base_Array<T>(length)
{
	//use the length constructor
}

//
// Array (size_t, value)
//
template <typename T>
Array <T>::Array (size_t length, T fill): Base_Array<T>(length, fill)
{
	//use the fill constructor
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array): Base_Array<T>(array)
{
	//use the copy constructor
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{

}

//
// operator =
//

template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	//(this != &rhs) compares the addresses. 
	//If the object is being assigned to itself, its caught and nothing happens
	
	//(*this != rhs) compares the actual objects.
	//It'll save time if many identical arrays are being compared to 
	//each other, but it'll waste time if the majority of arrays are not
	//similar
	
	if(this != &rhs)//check the addresses
	{
		delete [] this->data_;//get rid of the old data
		this->data_ = new T[rhs.max_size()];//allocate a new array
		this->cur_size_ = rhs.size();//set the sizes to their new values
		this->max_size_ = rhs.max_size();
		for(size_t i = 0; i < this->cur_size_; i++)
		{//iterate through the array, copying the rhs
			this->data_[i] = rhs[i];
		}
	}
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	if(new_size == 0)
	{//nullify data, zero out sizes
		this->data_ = NULL;
		this->cur_size_ = 0;
		this->max_size_ = 0;
	}
	
	else if(this->max_size_ < new_size)
	{//the array will need to be expanded

		T * hold = this->data_;//store the old data
		this->data_ = new T[new_size];//make a new array
		this->max_size_ = new_size;//reassign the maximum size to the new value
		for(size_t i = 0; i < this->cur_size_; i++)
		{//iterate through and copy the old array
			this->data_[i] = hold[i];
		}
		delete [] hold;
		//apparently this needs to be deleted.
		//thought the compiler would do this when it went out of scope.
	}

	else if(this->max_size_ > new_size)
	{//the array will need to be truncated
		
		if(this->cur_size_ > new_size)
		{//if the array is truncated past the previous last element
			this->cur_size_ = new_size;
		}
		T * hold = this->data_;//store the old data
		
		this->data_ = new T[new_size];//make a new array
		
		this->max_size_ = new_size;//reassign the maximum size to the new value
		for(size_t i = 0; i < this->cur_size_; i++)
		{//iterate through and copy the old array
			this->data_[i] = hold[i];
		}
		delete [] hold;
		//apparently this needs to be deleted.
		//thought the compiler would do this when it went out of scope.
	}

	else
	{//nothing needs to be done
		// Ryan: Perhaps look at breaking this out here.
		// Not sure what's being asked here, or why it is necessary.
		// The adjustment you appear to be pointing me to has pretty much
		// the same behavior.
		
		// Fix: Break statement threw error: Not in a loop.
		return;
	}
}
