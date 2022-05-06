#include "LinkedList.h"
#include <iostream>

int LinkedList::size() {
	return ln;
}

void LinkedList::add(int v) {
	++ln;

	box* tmp = new box(v);
	tmp->next = tmp->prev = tmp;
	if (root == nullptr) {
		root = tmp;
		return;
	}
	
	box* end = root->prev;
	root->prev = tmp;
	end->next = tmp;
	tmp->prev = end;
	tmp->next = root;
}


void LinkedList::show() {
	box* cur = root;
	for (int i = 0; i < size(); ++i) {
		std::cout << cur->key << ' ';
		cur = cur->next;
	}
}



void LinkedList::RevShow() {
	box* cur = root->prev;
	for (int i = 0; i < size(); ++i) {
		int x = cur->key;
		/*
		while (x > 0) {
			std::cout << x % 10;
			x /= 10;
		}
		*/
		std::cout << cur->key;
		cur = cur->prev;
	}
}

LinkedList operator +(LinkedList x, LinkedList y) {
	LinkedList res;

	if (x.size() > y.size())
		std::swap(x, y);

	int add = 0;
	box *it1 = x.root;
	box *it2 = y.root;
	for (int i = 0; i < x.size(); ++i) {
		res.add((add + it1->key + it2->key) % 1000000000);
		add = (add + it1->key + it2->key) / 1000000000;
		it1 = it1->next;
		it2 = it2->next;
	}
	for (int i = x.size(); i < y.size(); ++i) {
		res.add((add + it2->key) % 1000000000);
		add = (add + it2->key) / 1000000000;
		it2 = it2->next;
	}

	return res;
}

LinkedList CreateNumber(std::string s) {
	LinkedList a;

	reverse(s.begin(), s.end());
	for (int i = 0; i < (int)s.size(); i += 9) {
		std::string bl = s.substr(i, std::min(9, (int)s.size() - i * 9));
		reverse(bl.begin(), bl.end());
		a.add(atoi(bl.c_str()));
	}
	return a;
}
