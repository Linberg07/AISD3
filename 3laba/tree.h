#pragma once
#include "queue.h"
#include "stack.h"
#include "iterator.h"
#include "node.h"

#include<iostream>

using namespace std;
class dft_iterator : public Iterator {
private:
	Node* cur;
	stack nodesStack;
	bool bl = true;
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
		if (bl) {
			bl = false;
			Node* temp = nodesStack.getTop();
			nodesStack.pop();
			return temp->data;
		}
		if (cur->pRight != nullptr) nodesStack.push(cur->pRight);
		if (cur->pLeft != nullptr) cur = cur->pLeft;
		else
			if (!nodesStack.isEmpty()) {
				cur = nodesStack.getTop();
				nodesStack.pop();
			}
			else cur = nullptr;
		return cur->data;
	}

	bool has_next() override {
		if (cur->pLeft == nullptr && cur->pLeft == nullptr) return false;
		else return true;
	}

};
class bft_iterator : public Iterator {
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
		if (nodesQueue.getSize() > 0) {
			cur = nodesQueue.front();
			nodesQueue.pop();
			if (cur->pLeft != nullptr) {
				nodesQueue.push(cur->pLeft);
			}
			if (cur->pRight != nullptr) {
				nodesQueue.push(cur->pRight);
			}
			return cur->data;;
		}
		else cur = nullptr;
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
	Iterator* create_bft_iterator() {
		return new bft_iterator(root);
	}
	Iterator* create_dft_iterator() {
		return new dft_iterator(root);
	}
};

Binary_tree::Binary_tree()
{
	root = nullptr;
}

void Binary_tree::insert(int data)
{
	if (root == nullptr) {
		root = new Node(data);
	}
	else {
		Node* current = this->root;

		while (true) {

			if (current->data < data) {
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

			if (current->data > data) {
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

			if (current->data == data) break;

		}

	}
}

void Binary_tree::print_tree(Node* root)
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
	if (root == nullptr) throw "This tree is Empty!";
	Node* current = this->root;
	if (current->data == data) return true;
	while (current) {
		if (current->data < data) current = current->pRight;
		else if (current->data > data) current = current->pLeft;
		else {
			return true;
		}

	}
	return false;
}

void Binary_tree::remove(int data)
{
	if (root == nullptr) throw "This tree is Empty!";
	Node* current = this->root;

	while (current) {
		if (current->data < data) current = current->pRight;
		else if (current->data > data) current = current->pLeft;
		else if (current->data == data) {
			break;
		}
	}
	if (current==nullptr) throw "This element isn`t in tree";
	if (current->pLeft == nullptr && current->pRight == nullptr) {
		Node* cur_par = current->parents;
		if (current == cur_par->pLeft) cur_par->pLeft = nullptr;
		if (current == cur_par->pRight) cur_par->pRight = nullptr;
		delete current;
	}
	else if (current->pLeft == nullptr && current->pRight != nullptr) {
		Node* cur_par = current->parents;
		if (current == cur_par->pLeft) cur_par->pLeft = current->pRight;
		if (current == cur_par->pRight) cur_par->pRight = current->pRight;
		delete current;
	}
	else if (current->pRight == nullptr && current->pLeft != nullptr) {
		Node* cur_par = current->parents;
		if (current == cur_par->pLeft) cur_par->pLeft = current->pLeft;
		if (current == cur_par->pRight) cur_par->pRight = current->pLeft;
		delete current;
	}
	else if (current->pLeft != nullptr && current->pRight != nullptr) {

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

