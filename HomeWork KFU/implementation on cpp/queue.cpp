#include "queue.h"
#include <iostream>

men Parse(std::string x) {
	men elem;
	x += " ";

	int l = 0;
	int el = 0;
	for (int i = 0; i < x.size(); ++i) {
		if (x[i] != ' ') continue;
		if (el == 0)
			elem.name = x.substr(l, i - l);
		else if(el == 1)
			elem.gender = x.substr(l, i - l);
		else if(el == 2)
			elem.age = stoi(x.substr(l, i - l));
		else if(el == 3)
			elem.PlaceWork = x.substr(l, i - l);
		else if(el == 4)
			elem.income = stoi(x.substr(l, i - l));
		else if(el == 5)
			elem.goal = x.substr(l, i - l);
		el++;
		l = i + 1;
	}

	return elem;
}


int queue::size() {
	return ln;
}
	
void queue::push(men x) {
	node* elm = new node(x);

	if (end == nullptr) {
		begin = end = elm;
	}else{
		end->next = elm;
		end = end->next;
	}
	++ln;
}

men queue::front() {
	return begin->key;
}

bool queue::pop() {
	if (ln == 0)
		return false;
	node* tmp = begin;
	begin = begin->next;
	delete tmp;
	if (begin == nullptr)
		end = nullptr;
	--ln;
	return true;
}

void queue::clear() {
	while (ln > 0) {
		pop();
	}
}

std::string PackinngInTd(std::string x) {
	return "<td>" + x + "</td>";
}

std::string ToStr(int x) {
	if (x == 0)
		return "0";
	std::string s = "";
	while (x>0)
	{
		s += ('0' + x % 10);
		x /= 10;
	}
	for (int i = 0; i < s.size() / 2; ++i) {
		char c = s[i];
		s[i] = s[(int)s.size() - i - 1];
		s[(int)s.size() - i - 1] = c;
	}
	return s;
}

// Фамилия И. О. | пол | возраст | место работы | размер дохода (при наличии) | цель обращения (кредит/вклад)
void queue::show() {
	std::cout << "<h2>" << begin->key.goal << "</h2>";
	std::cout << "<table cellpadding=\"7\" border=\"2\" width=\"100\" >";
		
	node* cur = begin;
	while (cur != nullptr) {
		std::cout << "<tr>";
		std::cout << PackinngInTd(cur->key.name) << ' ';
		std::cout << PackinngInTd(cur->key.gender) << ' ';
		std::cout << PackinngInTd(ToStr(cur->key.age)) << ' ';
		std::cout << PackinngInTd(cur->key.PlaceWork) << ' ';
		std::cout << PackinngInTd(ToStr(cur->key.income)) << ' ';
		std::cout << "</tr>";
		std::cout << "\n";
		cur = cur->next;
	}
	std::cout << "</table>";
}
/*
void queue::readFile(std::ifstream& f) {
	std::string data;
	while (!f.eof()) {
		getline(f, data);
		men tmp = Parse(data);
		push(tmp);
	}
	data.clear();
}
*/
