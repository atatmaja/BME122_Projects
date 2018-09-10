#include "DynamicStack.hpp"
#include <iostream>

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	items_ = new StackItem[16];
	capacity_ = 16;
	init_capacity_ = 16;
	size_ = 0;	
}

DynamicStack::DynamicStack(unsigned int capacity)
{
	items_ = new StackItem[capacity];
	if (capacity == 0){
		capacity_ = 16;
	}
	capacity_ = capacity;
	init_capacity_ = capacity;
	size_ = 0;
}

DynamicStack::~DynamicStack()
{
	delete(items_);
}

bool DynamicStack::empty() const
{
	if (size_ == 0){
		return true;
	}
	else{
		return false;
	}
}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{
	if(size_ == capacity_){
		StackItem* newItems_ = new StackItem[capacity_*2];
		for (int i = 0; i < size_ ; i++){
			newItems_[i] = items_[i];
		}
		delete(items_);
		items_ = newItems_;
		newItems_ = NULL;
		capacity_ = capacity_ * 2;
	}
	items_[size_] = value;
	size_++;
}

StackItem DynamicStack::pop()
{
	//CHECK AGAIN!
	if (DynamicStack::empty() == true){
		return EMPTY_STACK;
	}
	else if (capacity_ / 4 >= size_ - 1 && capacity_/2 >= init_capacity_){
		StackItem* newItems_ = new StackItem[capacity_/2];
		for (int i = 0; i < size_ ; i++){
			newItems_[i] = items_[i];
		}
		delete(items_);
		items_ = newItems_;
		newItems_ = NULL;
		capacity_ = capacity_/2;
		size_--;
		return items_[size_];
	}
	else{
		size_--;
		return items_[size_];
	}
}

StackItem DynamicStack::peek() const
{
	if (DynamicStack::empty() == true){
		return EMPTY_STACK;
	}

	/*
	else if (capacity_ / 4 >= size_ - 1 && capacity_/2 >= init_capacity_){
		StackItem* newItems_ = new StackItem[capacity_/2];
		for (int i = 0; i < size_ ; i++){
			newItems_[i] = items_[i];
		}
		items_ = newItems_;	
		return items_[size_ - 1];
	}
	*/
	
	
	else{
		return items_[size_ - 1];
	}
}

void DynamicStack::print() const
{
	for (int i = 0; i < size_; i++){
		std::cout << items_[size_ - 1 - i] << std::endl;
	}
	
}
