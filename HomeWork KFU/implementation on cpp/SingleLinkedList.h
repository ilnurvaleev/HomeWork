#pragma once
#include <fstream>
#include <string>
struct elem{
	int key;
	elem* next = nullptr;

	elem(int _key);
};

struct SingleLinkedList{
	elem* root = nullptr;
	int ln = 0;
	void add(int _key);
	void insert(int _key, int pos);
	bool count(int _key);
	void clear();
	int erase();
	int size();

	void Show();
	void ReadData(std::ifstream& fin);
	bool SaveData(std::ofstream& fout);
};