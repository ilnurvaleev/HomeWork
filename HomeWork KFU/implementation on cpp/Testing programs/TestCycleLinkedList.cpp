// #define _GLIBCXX_DEBUG
#include <iostream>
#include "LinkedList.h"
using namespace std;


int ASS() {
    string s;
    cin >> s;
    LinkedList a = CreateNumber(s);
    a.show(); cout << endl;
    
    
    string x;
    cin >> x;
    LinkedList y = CreateNumber(x);
    y.show(); cout << endl;

    LinkedList c = a + y;
    c.RevShow();
    return 0;
}