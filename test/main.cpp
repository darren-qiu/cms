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

	cms_list<CMS_Body> list;
	cout << "size = " << list.size() << endl;

	return 0;
}

