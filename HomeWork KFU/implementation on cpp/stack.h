#pragma once
#include <iostream>
typedef long long int ll;

struct Node {
	ll value;
	Node* next;

	Node() {}
	Node(ll _value) {
		value = _value;
		next = nullptr;
	}
};

void push(Node*& root, ll value);
ll* peek(Node* root);
bool pop(Node*& root);
void clear(Node*& root);
void Show(Node* root);
void bracket(std::string s);