#pragma once
#include <string>

struct box{
	box *prev = nullptr, *next = nullptr;
	int key;

	box(int _key) {
		key = _key;
	}
};

struct LinkedList{
	box* root = nullptr;

	int ln = 0;
	int size();
	void add(int v);
	void show();
	void RevShow();
};

LinkedList operator +(LinkedList x, LinkedList y);
LinkedList CreateNumber(std::string s);