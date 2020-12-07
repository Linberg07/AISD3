#pragma once

class Node {
public:
	Node* pLeft; //the element is smaller than the current one and is on the left
	Node* pRight; //element larger than the current one and standing on the right
	Node* parents; //parent of element
	int data; //the value stored in this element
	Node(int data = NULL, Node* pLeft = nullptr, Node* pRight = nullptr, Node* parents = nullptr) {
		this->data = data;
		this->pLeft = pLeft;
		this->pRight = pRight;
		this->parents = parents;
	}
};