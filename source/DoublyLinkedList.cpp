#include "DoublyLinkedList.hpp"
#include <iostream>

//node constructor
DoublyLinkedList::Node::Node(DataType data)
{
	//REVISIT!!!!!!
	value = data;
	next = NULL;
	prev = NULL;	
}

//constructor??
DoublyLinkedList::DoublyLinkedList()
{
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
}

//destructor??
DoublyLinkedList::~DoublyLinkedList()
{
	Node* visitor = head_;
	if(size_ == 0){
		head_ = NULL;
		tail_ = NULL;
	}
	else if(size_ == 1){
		delete(head_);
		head_ = NULL;
		tail_ = NULL;
	}
	else{
		while (visitor != tail_){
		Node* after = visitor -> next;
		delete(visitor);
		visitor = after;
		}
		delete(tail_);
		tail_ = NULL;
		head_ = NULL;
	}
	size_ = 0;
}

bool DoublyLinkedList::empty() const
{
	if (size_ == 0){
		return true;
	}
	else{
		return false;
	}
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

void DoublyLinkedList::print() const
{
	Node* visitor = head_;
	for (int i = 0; i < size_; i++){
		std::cout << visitor -> value << " ";
		visitor = visitor -> next;
	}
	std::cout<<std::endl;
}

bool DoublyLinkedList::insert_front(DataType value)
{
	Node* insert = new Node(value);
	if(size_ == 0){
		head_ = insert;
		tail_ = insert;
		size_++;
		return true;
	}
	else{
		Node* visitor = head_;
		visitor -> prev = insert;
		head_ = insert;
		insert -> next = visitor;
		size_ ++;
		return true;
	}
	
}


bool DoublyLinkedList::remove_front()
{
	
	if (size_ == 0){
		return false;
	}
	else if(size_ == 1){
		delete(head_);
		head_ = NULL;
		tail_ = NULL;
		size_--;
		return true;
	}
	else{
		head_ = head_ -> next;
		delete (head_-> prev);
		//CHECK THIS
		head_->prev = NULL;
		size_ --;
		return true;
	}
	
	
}


bool DoublyLinkedList::insert_back(DataType value)
{
	
	Node* insert = new Node(value);
	if(size_ == 0){
		head_ = insert;
		tail_ = insert;
		size_ ++;
		return true;
	}
	else{
		Node* visitor = tail_;
		visitor -> next = insert;
		tail_ = insert;
		insert -> prev = visitor;
		size_ ++;
		return true;
	}
	
}

bool DoublyLinkedList::remove_back()
{
	
	if(size_ == 0){
		return false;
	}
	
	else if(size_ == 1){
		delete(tail_);
		tail_ = NULL;
		head_ = NULL;
		size_--;
		return true;
	}
	else{
		tail_ = tail_ -> prev;
		delete (tail_-> next);
		//CHECK THIS
		tail_->next = NULL;
		size_ --;
		return true;	
	}
	
		
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	Node* insert = new Node(value);
	if(index > size_){
		return false;
	}
	//insert to head case
	else if(index == 0){
		return insert_front(value);
	}
	//insert to tail case
	else if(index == size_){
		return insert_back(value);
	}
	else{
		Node* visitor = head_;
		for(int i = 0; i < index; i++){
			visitor = visitor -> next;	
		}
		Node* before = visitor->prev;
		insert->prev = before;
		insert->next = visitor;
		before->next = insert;
		visitor->prev = insert;
		size_ ++;
		return true;
	}
}

bool DoublyLinkedList::remove(unsigned int index)
{
	if(size_ == 0){
		return false;
	}
	else if(index >= size_){
		return false;
	}
	else if(size_ == 1){
		delete(head_);
		head_ = NULL;
		tail_ = NULL;
		size_--;
		return true;
	}
	//head case
	else if(index == 0){
		DoublyLinkedList::remove_front();
	}
	//tail case
	else if(index == size_ - 1){
		DoublyLinkedList::remove_back();
	}
	else{
		Node* visitor = head_;
		for(int i = 0; i < index; i++){
			visitor = visitor -> next;	
		}
		Node* after = visitor -> next;
		Node* before = visitor -> prev;
		before->next = after;
		after -> prev = before;
		delete(visitor);
		visitor = NULL;
		size_--;
		return true; 
	}
	
}

unsigned int DoublyLinkedList::search(DataType value) const
{
	if(size_ == 0){
		return size_;
	}
	else if(size_ == 1){
		if(head_->value == value){
			return 0;
		}
		else{
			return size_;
		}
	}
	else{
		Node* visitor = head_;
		for (int i = 0; i < size_; i++){
			if(visitor -> value == value){
				return i;
			}
			else{
				visitor = visitor -> next;
			}
		}
		return size_;	
	}
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
	if (index >= size_){
		return tail_ -> value;
	}
	else if (size_ == 0){
		return 0;
	}
	else{
		Node* visitor = head_;
		for (int i = 0; i < index; i++){
			visitor = visitor->next;
		}
		return visitor -> value;
	}

}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
	if(size_ == 0){
		return false;
	}
	//if index is out of bounds
	else if(index >= size_){
		return false;
	}
	else{
		Node* visitor = head_;
		for (int i = 0; i < index; i++){
			visitor = visitor->next;
		}
		visitor -> value = value;
		return true;
	}
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
	
	if(size_ == 0){
		return NULL;
	}
	else if(index >= size_){
		return NULL;
	}
	else{
		Node* visitor = head_;
		for (int i = 0; i < index; i++){
			visitor = visitor->next;
		}
		return visitor;
	}
	
}
bool DoublyLinkedList::full() const
{
	if(size_ == 0){
		return false;
	}
	else{
		return true;
	}
}
