#include <stdint.h>
#include <iostream>
#include "cms_list.h"

using namespace std;

int main(int argc, char* argv[]) {

	typedef struct cms_body {
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
				this->deadline = body.msgid;
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
	} CMS_Body;

	typedef cms_node<CMS_Body>* pointer;
	cms_list<CMS_Body> list;
	CMS_Body body;
	body.msgid = 1;
	body.deadline =1;
	body.flag = true;
	pointer p = list.push_top(body);
	cout << "size = " << list.size() << endl;
	p = list.pop_top();
	cout << "msgid = " << p->data.msgid << endl;
	

	return 0;
}

