#include <iostream>
#include "mlist.h"

using namespace std;

int main(int argc, char* argv[]) {
	cout << "this is a test about message list." << endl;
	
	CMS_MList list;
	cout << "init complate, the size is " << list.size() << endl;
	CMS_MBody b;
	b._msgid = 1;
	list.set(b);
	CMS_MBody *p = list.get(1);
	cout << "the size " << list.size() << ", msgid " << p->value() << endl;

	b._msgid = 2;
	list.set(b);
	p = list.get(2);
	cout << "the size " << list.size() << ", msgid " << p->value() << endl;

	b._msgid = 4;
	list.set(b);
	p = list.get(4);
	cout << "the size " << list.size() << ", msgid " << p->value() << endl;

	int i = 0;
	while(list.size() > 0) {
		list.del(i++);
		cout << "i " << i << ", size is " << list.size() << endl;
	}

	return 0;
}

