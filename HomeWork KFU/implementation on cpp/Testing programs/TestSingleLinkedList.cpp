// #define _GLIBCXX_DEBUG
#include <iostream>
#include "SingleLinkedList.h"
using namespace std;

int main2() {
    SingleLinkedList q;
    ifstream fin("test.txt");
    q.ReadData(fin);
    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        cout << q.count(x) << "\n";
        if (!q.count(x))
            q.add(x);
    }
    ofstream fout("test.txt");
    q.SaveData(fout);
    return 0;
}