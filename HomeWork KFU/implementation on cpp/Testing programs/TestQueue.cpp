#include <fstream>
#include "Header.h"
#include "queue.h"
#include <string>
using namespace std;

#define len(a) (ll)a.size()

void TestQueue() {
	ifstream fin("test.txt");
	queue q;

	q.readFile(fin);
	q.show();

	return;
}
