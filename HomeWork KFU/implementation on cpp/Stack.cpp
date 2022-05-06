#include "stack.h"
/*
struct Node {
	ll value;
	Node* next;

	Node() {}
	Node(ll _value) {
		value = _value;
		next = nullptr;
	}
};
*/


void push(Node*& root, ll value) {
	Node* NewNode = new Node(value);

	if (root == nullptr)
		root = NewNode;
	else {
		NewNode->next = root;
		root = NewNode;
	}
}


ll* peek(Node* root) {
	if (root == nullptr)
		return nullptr;
	return &root->value;
}


bool pop(Node*& root) {
	if (root == nullptr)
		return false;

	Node* NewNode = root;
	root = root->next;
	delete NewNode;
	return true;
}

void clear(Node*& root) {
	while (root != nullptr) {
		Node* NewNode = root;
		root = root->next;
		delete NewNode;
	}
}

void Show(Node* root) {
	Node* tmp = root;
	std::string res = "";
	while (tmp != nullptr) {
		std::cout << tmp->value + 1 << " ";
		if(!pop(root))
			break;
	}
}