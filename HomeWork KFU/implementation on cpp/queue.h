#pragma once
#include <string>
#include <fstream>

// Фамилия И. О. | пол | возраст | место работы | размер дохода (при наличии) | цель обращения (кредит/вклад)
struct men {
	std::string name = "";
	std::string gender = "";
	int age = 0;
	std::string PlaceWork = "";
	int income = 0;
	std::string goal = "";

	men() {}
	men(std::string _name, std::string _gender, int _age, std::string _place, int _income, std::string _goal) {
		name = _name;
		gender = _gender;
		age = _age;
		PlaceWork = _place;
		income = _income;
		goal = _goal;
	}
};

men Parse(std::string x);

struct node {
	men key;
	node* next = nullptr;
	node() {}
	node(men _key) {
		key = _key;
	}
};


struct queue {
	node* begin = nullptr;
	node* end = nullptr;
	int ln = 0;

	int size();
	void push(men x);
	men front();
	bool pop();
	void clear();
	void show();
	//void readFile(std::ifstream& f);
};