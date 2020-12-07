#pragma once
#include "queue.h"
#include "stack.h"
#include "iterator.h"
#include "node.h"

#include<iostream>

using namespace std;
class dft_iterator : public Iterator { ///depth-first iterator
private:
	Node* cur;
	stack nodesStack;
	bool label = true; //label showing we are working with the last element of the stack or not
public:
	dft_iterator(Node* root) {
		cur = root;
		if (cur != nullptr) {
			nodesStack.push(cur);
		}
		else {
			throw "This tree is empty";
		}
	}

	int next() override {
		if (label) {
			label = false;
			Node* temp = nodesStack.getTop(); // assign temp element from the stack
			nodesStack.pop(); // immediately remove the assigned value
			return temp->data; // return value
		}
		if (cur->pRight != nullptr) nodesStack.push(cur->pRight); // if the element has a right element add to the stack

		if (cur->pLeft != nullptr) cur = cur->pLeft; // same with the left
		else
			if (!nodesStack.isEmpty()) { // if the stack is not empty
				cur = nodesStack.getTop(); // assign the variable an item from the stack
				nodesStack.pop(); // immediately remove the assigned value
			}
			else cur = nullptr; 
		return cur->data;
	}

	bool has_next() override {
		if (cur->pLeft == nullptr && cur->pLeft == nullptr) return false;
		else return true;
	}

};

class bft_iterator : public Iterator {  //breadth - first iterator
private:
	Node* cur;
	queue nodesQueue;
public:
	bft_iterator(Node* root) {
		cur = root;
		if (cur != nullptr) {
			nodesQueue.push(cur);
		}
		else {
			throw "This tree is empty";
		}
	}

	int next() override {
		if (nodesQueue.getSize() > 0) { //if heap size is greater than 0
			cur = nodesQueue.front(); //take an element from the heap from the beginning
			nodesQueue.pop(); //remove the element from the beginning 
			if (cur->pLeft != nullptr) { //if element has a left element
				nodesQueue.push(cur->pLeft); //insert the left element at the end of the heap
			}
			if (cur->pRight != nullptr) { //the same with the right
				nodesQueue.push(cur->pRight);
			}
			return cur->data;; //return the value of the element
		}
		else cur = nullptr;  //otherwise the element does not exist
	}

	bool has_next() override {
		if (cur->pLeft == nullptr && cur->pRight == nullptr) return false;
		else return true;
	}
};


class Binary_tree {
private:


public:
	Binary_tree();
	
	void insert(int data);
	void print_tree(Node* root);
	bool contains(int data);
	void remove(int data);
	Node* root;
	Iterator* create_bft_iterator() { //creating a breadth - first iterator
		return new bft_iterator(root); 
	}
	Iterator* create_dft_iterator() { //creating a depth-first iterator
		return new dft_iterator(root);
	}
};

Binary_tree::Binary_tree() 
{
	root = nullptr; //initially the root of the tree does not exist
}

void Binary_tree::insert(int data)
{
	if (root == nullptr) { //if the tree is empty, create the root of the tree and insert the value there
		root = new Node(data); 
	}
	else {
		Node* current = this->root; //assign the root of the tree to the temporary pointer


		while (true) { //until the element falls into place


			if (current->data < data) { //if the element that needs to be inserted is larger than the element in this cell of the tree, 
										//then we insert it to the right of this cell if it is free there, otherwise we go to the right cell
				if (current->pRight == nullptr) {
					current->pRight = new Node(data); 
					current->pRight->parents = current;
					break;
				}
				if (current->pRight != nullptr) {
					current = current->pRight;
					continue;
				}
			}

			if (current->data > data) { //the same as with the right cell only on the left, if the element to be inserted is smaller
										//than the element in the given cell
				if (current->pLeft == nullptr) {
					current->pLeft = new Node(data);
					current->pLeft->parents = current;
					break;
				}
				if (current->pLeft != nullptr) {
					current = current->pLeft;
					continue;
				}
			}
			 //if such an element is already in the tree, exit the loop and do not insert it
			if (current->data == data) break;

		}

	}
}

void Binary_tree::print_tree(Node* root) //a function that displays all the elements of the tree
{

	if (root == nullptr) return;
	if (root->pLeft == nullptr && root->pRight == nullptr) cout << root->data << " ";
	else {
		cout << root->data << " ";
		print_tree(root->pRight);
		print_tree(root->pLeft);


	}

}

bool Binary_tree::contains(int data)
{
	if (root == nullptr) throw "This tree is Empty!"; //if there is no tree root, then the tree is empty
	Node* current = this->root;//assign the root of the tree to the temporary pointer
	if (current->data == data) return true; // if the tree is the desired value, we immediately return the truth
	while (current) { //loop until we reach a nonexistent element
		if (current->data < data) current = current->pRight; 
		else if (current->data > data) current = current->pLeft;
		else {
			return true;
		}

	}
	return false; //if nothing was found, then the element is not in the tree
}

void Binary_tree::remove(int data)
{
	if (root == nullptr) throw "This tree is Empty!"; //if there is no tree root, then the tree is empty
	Node* current = this->root;//assign the root of the tree to the temporary pointer

	while (current) {  //see if there is a given value in the tree at all
		if (current->data < data) current = current->pRight;
		else if (current->data > data) current = current->pLeft;
		else if (current->data == data) {
			break;
		}
	}
	if (current==nullptr) throw "This element isn`t in tree"; //if the pointer has reached a non-existent value,
															 //then the element is not in the tree
	if (current->pLeft == nullptr && current->pRight == nullptr) { //if the element does not have a right and left element, 
																   //then simply delete it and update the information about which element
																   //its parent points to
		Node* cur_par = current->parents;
		if (current == cur_par->pLeft) cur_par->pLeft = nullptr;
		if (current == cur_par->pRight) cur_par->pRight = nullptr;
		delete current;
	}
	else if (current->pLeft == nullptr && current->pRight != nullptr) { //if the element does not have a left element but has a right one, 
																		//then put the right element in its place, and delete the element itself
		Node* cur_par = current->parents;
		if (current == cur_par->pLeft) cur_par->pLeft = current->pRight;
		if (current == cur_par->pRight) cur_par->pRight = current->pRight;
		delete current;
	}
	else if (current->pRight == nullptr && current->pLeft != nullptr) { //similar to the left
		Node* cur_par = current->parents;
		if (current == cur_par->pLeft) cur_par->pLeft = current->pLeft;
		if (current == cur_par->pRight) cur_par->pRight = current->pLeft;
		delete current;
	}
	else if (current->pLeft != nullptr && current->pRight != nullptr) { //if there is both right and left element, find the largest element by value on 
																		//the left and put it in place

		Node* max_elem;
		Node* cur_par;
		Node* cur_left = current->pLeft;
		while (cur_left->pRight != nullptr) {
			cur_left = cur_left->pRight;
		}
		cur_par = cur_left->parents;
		if (cur_left == cur_par->pLeft) cur_par->pLeft = nullptr;
		if (cur_left == cur_par->pRight) cur_par->pRight = nullptr;
		current->data = cur_left->data;
		delete cur_left;
	}

}

