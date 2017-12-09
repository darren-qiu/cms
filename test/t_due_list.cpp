#include <iostream>
#include "overdue.h"

using namespace std;

int main(int argc, char* argv[]) {
	cout << "this is a test about over due list. " << endl;

	CMS_Due due;
	cout << "init complate. the size is " << due.size() << endl;
	
	CMS_DUEBody b;
	b.deadline = 4;
	due.push(b);
	CMS_P_DNode p = due.begin();
	cout << "add a 4, the size is " << due.size() << ", begin is " << p->data.value() << endl;

	b.deadline = 5;
	due.push(b);
	p = due.begin();
	cout << "add a 5, the size is " << due.size() << ", begin is " << p->data.value() << endl;

	b.deadline = 3;
	due.push(b);
	p = due.begin();
	cout << "add a 3, the size is " << due.size() << ", begin is " << p->data.value() << endl;

	while(due.size() > 0) {
		CMS_P_DNode q = due.begin();
		cout << "size is " << due.size() << ", the begin value is " << q->data.value();
		//CMS_P_DNode q2 = q;
		due.erase(q);
		cout << ", after, the size is " << due.size() << endl;
	}

	return 0;
}

