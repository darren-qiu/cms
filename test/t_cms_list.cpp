#include <stdint.h>
#include <iostream>
#include "cms_list.h"

using namespace std;

class cms_body {
public:
    uint64_t msgid;
    uint64_t deadline;
    bool flag;
	cms_body() {}
    ~cms_body() {}
	cms_body(const cms_body& body) {
        msgid = body.msgid;
		deadline = body.deadline;
        flag = body.flag;
    }
	cms_body& operator = (const cms_body& body) {
        if(this != &body) {
			this->msgid = body.msgid;
            this->deadline = body.deadline;
            this->flag = body.flag;
        }
		return *this;
    }
    bool operator < (const cms_body& body) {
		if(deadline < body.deadline) {
            return true;
        } else {
			return false;
        }
    }
    uint64_t value() {
		return deadline;
    }
};

typedef cms_body CMS_Body;

int main(int argc, char* argv[]) {

	typedef const cms_node<CMS_Body>* pointer_const;
	typedef cms_node<CMS_Body>* pointer;
	typedef cms_list<CMS_Body> List;

	List list;
	CMS_Body body;
	
	body.msgid = 1;
	body.deadline =1;
	body.flag = true;
	
	pointer_const p = list.push_top(body);
	cout << "size = " << list.size() << endl;
	pointer q = list.begin();
	cout << "msgid = " << q->data.msgid << endl;
	cout << "size = " << list.size() << endl;

	p = list.push_top(body);
	p = list.push_top(body);
	p = list.push_top(body);
	cout << "size = " << list.size() << endl;

	q = list.begin();
	cout << "msgid = " << p->data.msgid << endl;
	cout << "size = " << list.size() << endl;
	list.free_node(q);
	cout << "msgid = " << p->data.msgid << endl;
	cout << "size = " << list.size() << endl;

	List list2;
	body.deadline = 2;
	if( NULL  == list2.push_sort(body) ) {
		cout << "push error " << endl;
		return -1;
	}
	q = list2.begin();
	cout << "begin.1 2 " << q->data.deadline << endl;
	body.deadline = 5;
	if( NULL == list2.push_sort(body) ) {
		cout << "push error " << endl;
		return -1;
	}
	q = list2.begin();
	cout << "begin.2 5 " << q->data.deadline << endl;
	body.deadline = 1;
	if( NULL == list2.push_sort(body) ) {
		cout << "push error " << endl;
		return -1;
	}
	q = list2.begin();
	cout << "begin.3 1 " << q->data.deadline << endl;

	return 0;
}

