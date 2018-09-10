#include "BinarySearchTree.hpp"
#include <iostream>
#include <queue>

typedef BinarySearchTree::DataType DataType;
BinarySearchTree::Node::Node(DataType newval){
	left = NULL;
	right = NULL;
	val = newval;
}
BinarySearchTree::BinarySearchTree(){
	root_ = NULL;
	size_ = 0;
}
BinarySearchTree::~BinarySearchTree(){
	for (int i = 0; i < size_; i++){
		remove(root_ -> val);
	}
}
bool BinarySearchTree::insert(DataType val){
	Node* v = root_;
	Node* v2 = root_;
	Node* insert = new Node(val);
	
	if(exists(val)){
		return false;
	}
	if(v == NULL){
		root_ = insert;
		size_++;
		return true;
	}
	while (true){
		if(val > v -> val){
			v = v -> right;
			if(v == NULL){
				v2 -> right = insert;
				size_++;
				return true;
			}
			v2 = v;
		}
		else if(val < v -> val){
			v = v -> left;
			if(v == NULL){
				v2 -> left = insert;
				size_++;
				return true;
			}
			v2 = v;
		}
		else{
			return false;
		}
	}
}
//REMOVE NEEDS WORK
bool BinarySearchTree::remove(DataType val){
	
	Node* v = root_;
	if (BinarySearchTree::exists(val) == true){
		//traversing to the value
	while (v != NULL){
		if(val > v -> val){
			v = v -> right;
		}
		else if(val < v -> val){
			v = v -> left;
		}
		else{
			break;
		}
	}
		
	
		//v2 will be parent of visited node
		Node* v2 = root_;
		if (v != root_){
			while(v2 -> right != v && v2 -> left != v){
				if (val > v2 -> val){
					v2 = v2 -> right;
				}
				else if (val < v2 -> val){
					v2 = v2 -> left;
				}
			}	
		}
		
		//no child case
		if(v -> right == NULL && v -> left == NULL){
				//If node to be deleted is the root
				if (v == root_){
					delete(v);
					v = NULL;
					size_--;
					root_ = NULL;
					return true;
				}
				else if(v2 -> right == v){
					v2 -> right = NULL;
				}
				else if (v2 -> left == v){
					v2 -> left = NULL;
				}
				delete(v);
				v = NULL;
				size_--;
				return true;	
			}
			
		//v has right child but not left
			else if(v -> right != NULL && v -> left == NULL){
				if (v == root_){
					Node* v3 = v -> right;
					root_ = v3;
					delete(v);
					v = NULL;
					size_--;
					return true;
				}
				
				Node* v3 = v -> right;
				if(v2 -> right == v){
					v2 -> right = v3;
				}
				else if (v2 -> left == v){
					v2 -> left = v3;
				}
				delete(v);
				v = NULL;
				size_--;
				return true;
			}
			//v has left child but not right
			else if (v -> left != NULL && v -> right == NULL){
				//When the node is the root
				if (v == root_){
					v2 = v -> left;
					root_ = v2;
					delete(v);
					v = NULL;
					size_--;
					return true;
				}
				//initializing child pointer
				Node* v3 = v -> left;
				
				//if v is a right child
				if(v2 -> right == v){
					v2 -> right = v3;
				}
				//if v is a left child
				else if (v2 -> left == v){
					v2 -> left = v3;
				}
				delete(v);
				v = NULL;
				size_--;
				return true;
			}
			
			//v has two children
			else if(v -> left != NULL && v -> right != NULL ){
				//finding smallest key in v's right subtree.
				Node* v3 = v -> right;
				while(v3 -> left != NULL){
					v3 = v3 -> left;
				}
				//switching the vals of v and v3
				DataType temp = v3 -> val;
				if (remove(temp) == false){
					return false;
				}
				v -> val = temp;
				return true;			
			}
	}
	else{
		return false;
	}
}

bool BinarySearchTree::exists(DataType val) const{
	Node* v = root_;
	while (v != NULL){
		if(val > v -> val){
			v = v -> right;
		}
		else if(val < v -> val){
			v = v -> left;
		}
		else if (val == v -> val){
			return true;
		}
	}
	return false;
}
//CHECK MAX AND MIN	
DataType BinarySearchTree::min() const{
	Node* v = root_;
	DataType result = v -> val;
	while(v -> left != NULL){
		v = v -> left;
		result = v -> val;
	}
	return result;
}
DataType BinarySearchTree::max() const{
	Node* v = root_;
	DataType result = v -> val;
	while(v -> right != NULL){
		v = v -> right;
		result = v -> val;
	}
	return result;	
}
unsigned int BinarySearchTree::size() const{
	return size_;
}
int BinarySearchTree::getNodeDepth(Node* n) const{
	int leftheight = 0;
	int rightheight = 0;
	if (n -> left != NULL){
		leftheight = 1 + getNodeDepth(n -> left);
	}
	else if (n -> right != NULL){
		rightheight = 1 + getNodeDepth(n -> right);
	}
	if (leftheight > rightheight){
		return leftheight++;
	}
	else{
		return rightheight++;
	}
}
unsigned int BinarySearchTree::depth() const{
	if (size_ == 0){
		return 0;
	}
	else{
		return getNodeDepth(root_);
	}
}
void BinarySearchTree::print() const{
	//level order print
	std::queue <Node*> que;
	int count = 0;
	Node* v = root_;
	que.push(v);
	while (count < size_){
		v = que.front();
		std::cout << v -> val<< " ";
		count++;
		
		if (v -> left != NULL){
			que.push(v -> left);
		}
		if (v -> right != NULL){
			que.push(v -> right);
		}
		que.pop();
	}
	std::cout << std::endl;
}
// Implement the functions here.


