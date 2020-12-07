#pragma once

class Node {
public:
	Node* pLeft;
	Node* pRight;
	Node* parents;
	int data;
	Node(int data = NULL, Node* pLeft = nullptr, Node* pRight = nullptr, Node* parents = nullptr) {
		this->data = data;
		this->pLeft = pLeft;
		this->pRight = pRight;
		this->parents = parents;
	}
};