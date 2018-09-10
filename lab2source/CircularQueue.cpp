#include<cstring>
#include<iostream>
#include "CircularQueue.hpp"

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
	items_ = new QueueItem[16];
	capacity_ = 16;
	size_ = 0;
	head_ = 0;
	tail_ = 1;
}

CircularQueue::CircularQueue(unsigned int capacity)
{
	items_ = new QueueItem[capacity];
	capacity_ = capacity;
	size_ = 0;
	head_ = 0;
	tail_ = 1;
}

CircularQueue::~CircularQueue()
{
	delete(items_);
}

bool CircularQueue::empty() const
{
	if (size_ == 0){
		return true;
	} 
	else{
		return false;
	}  
}

bool CircularQueue::full() const
{
	if (size_ >= capacity_){
		return true;
	}
	else{
		return false;
	}
}

int CircularQueue::size() const
{
	return size_;  
}

bool CircularQueue::enqueue(QueueItem value)
{
	//CHECK AGAIN
	if (size_ >= capacity_){
		return false;
	}
	else{
		if(size_ == 0){
			items_[0] = value;
		}
		else{
			items_[tail_] = value;
			tail_ = (tail_ + 1) % capacity_;
		}
		size_++;
		return true;
	}
}

QueueItem CircularQueue::dequeue()
{
	//CHECK AGAIN
	if (CircularQueue::empty() == true){
		return EMPTY_QUEUE;
	}
	else{
		int temp = head_;
		head_ = (head_ + 1) % capacity_;
		size_--;
		return items_[temp];
	}
}

QueueItem CircularQueue::peek() const
{
	//CHECK AGAIN
	if (CircularQueue::empty() == true){
		return EMPTY_QUEUE;
	}
	else{
		return items_[head_];
	}
}

void CircularQueue::print() const
{
	for(int i = 0; i < size_; i++){
		std::cout<< items_[head_ + i] << std::endl;
	}
}
