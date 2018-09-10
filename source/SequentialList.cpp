#include "SequentialList.hpp"
#include <iostream>

//constructor??
SequentialList::SequentialList(unsigned int cap)
{
	data_ = new DataType[cap];
	size_ = 0;
	capacity_ = cap;
}

//destructor??
SequentialList::~SequentialList()
{
	delete(data_);
}

bool SequentialList::empty() const
{
	if (size_ == 0){
		return true;
	}
	else{
		return false;
	}
}

unsigned int SequentialList::size() const
{
	return size_;
}

unsigned int SequentialList::capacity() const
{
	return capacity_;
}

bool SequentialList::full() const
{
	if (size_ == capacity_){
		return true;
	}
	else{
		return false;
	}
}

void SequentialList::print() const
{
	for (int i = 0; i < size_; i++)
	{
		std::cout << data_[i];
	}
}

bool SequentialList::insert_front(DataType val)
{
	if (size_ == capacity_){
		return false;
	}
	else if (size_ == 0){
		data_[0] = val;
		size_ ++;
		return true;
	}
	else{
		unsigned int tempIndex = size_;
		//shuffling the list
		for (int i = tempIndex; i > 0; i--){
			data_[i] = data_[i - 1];
		}
		//filling the 0th index
		data_[0] = val;
		size_ ++;
		return true;
	}
}

bool SequentialList::remove_front()
{
	if(size_ == 0){
		return false;
	}
	else{
		for (int i = 0; i < size_ - 1; i++){
			data_[i] = data_[i+1];
		}
		size_--;
		return true;
	}
}

bool SequentialList::insert_back(DataType val)
{
	
	if(size_ == capacity_){
		return false;
	}
	else{
		data_[size_] = val;
		size_++;
		return true;
	}
	
}

bool SequentialList::remove_back()
{
	if(size_ ==0){
		return false;
	}
	else{
		size_--;
		return true;
	}
}

bool SequentialList::insert(DataType val, unsigned int index)
{
	if (size_ == capacity_){
		return false;
	}
	else if (index == 0){
		SequentialList::insert_front(val);
	}
	else if (index > size_){
		return false;
	}
	else{
		unsigned int tempIndex = size_;
		//shuffling the list
		for (int i = tempIndex; i >= index; i--){
			data_[i] = data_[i - 1];
		}
		//filling the value at the index
		data_[index] = val;
		size_ ++;
		return true;
	}	
}

bool SequentialList::remove(unsigned int index)
{
	if (size_ == 0){
		return false;
	}
	else if(index >= size_){
		return false;
	}
	else if (index==size_ - 1){
		size_--;
		return true;
	}
	else{
		for (int i = index; i < size_; i++){
			data_[i] = data_[i+1];
		}
		size_--;
		return true;
	}
}

unsigned int SequentialList::search(DataType val) const
{
	if(size_ == 0){
		return size_;
	}
	else{
		for(int i = 0; i < size_; i++){
			if(data_[i] == val){
				return i;
			}
		}
		return size_;
	}
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if(index > size_ - 1){
		return data_[size_ - 1];
	}
	else if(size_ == 0){
		return -1;
	}
	else{
		return data_[index];
	}
}

bool SequentialList::replace(unsigned int index, DataType val)
{
	if(index > size_-1){
		return false;
	}
	else{
		data_[index] = val;
		return true;
	}
	
}
