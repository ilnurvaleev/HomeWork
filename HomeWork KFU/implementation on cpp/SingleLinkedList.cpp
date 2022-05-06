#include "SingleLinkedList.h"
#include <iostream>
elem::elem(int _key) {
	this->key = _key;
	this->next = nullptr;
}

void SingleLinkedList::add(int _key) {
	elem* tmp = new elem(_key);
	if (root == nullptr) {
		root = tmp;
		return;
	}

	elem* cur = root;
	while (cur->next != nullptr)
		cur = cur->next;
	cur->next = tmp;
	++ln;
}
void SingleLinkedList::insert(int _key, int pos) {
	elem* tmp = new elem(_key);
	if (pos <= 0) {
		tmp->next = root;
		root = tmp;
		return;
	}
	
	elem* cur = root;
	while (--pos > 0) 
		cur = cur->next;

	tmp->next = cur->next;
	cur->next = tmp;
	++ln;
}

bool SingleLinkedList::count(int _key) {
	if (root == nullptr) return false;
	elem* cur = root;
	do {
		if (cur->key == _key)
			return true;
		cur = cur->next;
	} while (cur != nullptr);
	return false;
}

void SingleLinkedList::ReadData(std::ifstream& fin) {
	if (!fin.is_open()) return;
	std::string s = "";
	while (getline(fin, s))
		add(atoi(s.c_str()));
	fin.close();
}

bool SingleLinkedList::SaveData(std::ofstream& fout){
	if (!fout.is_open()) return false;
	elem* cur = root;
	while (cur != nullptr) {
		fout << cur->key << '\n';
		cur = cur->next;
	}
	fout.close();
}

int SingleLinkedList::erase() {
	if (root == nullptr) return -1;
	elem* rem = root;
	int key = rem->key;
	root = root->next;
	delete rem;
	--ln;
	return key;
}

void SingleLinkedList::clear() {
	while (ln > 0){
		erase();
	}
}

int SingleLinkedList::size() {
	return ln;
}

void SingleLinkedList::Show() {
	elem* cur = root;
	std::cout << "<div>";
	while (cur != nullptr) {
		std::cout << cur->key << " ";
		cur = cur->next;
	}
	std::cout << "</div>";
}