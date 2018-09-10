#include "PriorityQueue.hpp"
#include <iostream>
typedef PriorityQueue::DataType DataType;

PriorityQueue::PriorityQueue(unsigned int capacity){
	heap_ = new DataType[capacity + 1];
	size_ = 0;
	capacity_ = capacity;
}
PriorityQueue::~PriorityQueue(){
	delete(heap_);
	heap_ = NULL;
}
bool PriorityQueue::enqueue(DataType val){
	//something wrong with this method??????
	int insertpos = size_ + 1;
	if (size_ == capacity_){
		return false;
	}
	else if(size_ == 0){
		heap_[1] = val;
	}
	else{
		//insert as bottom right most leaf
		heap_[insertpos] = val;
		DataType temp;
		//if parent has smaller val than node, switch
		while(heap_[insertpos] > heap_[insertpos/2] && insertpos > 1){
			temp = heap_[insertpos/2];
			heap_[insertpos/2] = heap_[insertpos];
			heap_[insertpos] = temp;
			insertpos = insertpos/2;
		}
		
	}
	size_ ++;
	return true;	
}
bool PriorityQueue::dequeue(){
	
	if(PriorityQueue::empty())
	{
		return false;
	}
	else if(size_==1)
	{
		size_--;
		return true;		
	}
	else
	{
		heap_[1]= heap_[size_];
		size_--;
		int currentpos = 1;
		DataType temp_;
		while (size_>=2*currentpos)
		{
			if(2*currentpos+1<=size_)
			{
				if(heap_[2*currentpos] >= heap_[2*currentpos + 1]&& heap_[2*currentpos]>heap_[currentpos])
				{
					temp_ = heap_[currentpos];
						heap_[currentpos]=heap_[2*currentpos];
						heap_[2*currentpos]= temp_;
						currentpos = 2*currentpos;
				}
				else if(heap_[2*currentpos] < heap_[2*currentpos + 1] && heap_[2*currentpos + 1]>heap_[currentpos])
				{
					temp_ = heap_[currentpos];
						heap_[currentpos]=heap_[2*currentpos + 1];
						heap_[2*currentpos + 1] = temp_;
						currentpos = 2*currentpos+1;
				}
				else{
					return true;
				}
			}
			else
			{
				if(heap_[2*currentpos]>heap_[currentpos])
				{
					temp_ = heap_[currentpos];
					heap_[currentpos]=heap_[2*currentpos];
					heap_[2*currentpos]= temp_;
					currentpos = 2*currentpos;
				}
				else
				{
						return true;
				}
			}
			
		
			
		}
		return true;
	}
	
	
}
bool PriorityQueue::empty() const{
	if (size_ == 0){
		return true;
	}
	return false;
}
bool PriorityQueue::full() const{
	if(size_ == capacity_){
		return true;
	}
	else{
		return false;
	}
}
unsigned int PriorityQueue::size() const{
	return size_;
}
DataType PriorityQueue::max() const{
	if(size_ >= 1){
		return heap_[1];
	}
	else{
		return -1;
	}
}
void PriorityQueue::print() const{
	for (int i = 1; i <= size_; i++){
		std::cout<< heap_[i] << " ";
	}
	std::cout << std::endl;
}

// Implement the functions here.

