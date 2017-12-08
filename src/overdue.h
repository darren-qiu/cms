#ifndef overdue_h
#define overdue_h

#include <string>
#include "cms_list.h"

using namespace std;

typedef class cms_duenode {
private:
	uint64_t msgid;
	uint64_t deadline;
	bool flag;		// false: default value, true: is system message that is due
	string mainkey;
public:
	cms_duenode() {
		this->msgid = 0;
		this->deadline = 0;
		this->flag = false;
		this->mainkey = "";
	}
	~cms_duenode() {
	};
	cms_duenode(const cms_duenode& node) {
		this->msgid = node.msgid;
		this->deadline = node.deadline;
		this->flag = node.flag;
		this->mainkey = node.mainkey;
	}
	cms_duenode& operator=(const cms_duenode& node) {
		if(this != &node) {
			this->msgid = node.msgid;
			this->deadline = node.deadline;
			this->flag = node.flag;
			this->mainkey = node.mainkey;
		}
		return *this;
	}
	bool operator<(const cms_duenode& node) {
		if(this->deadline < node.deadline) {
			return true;
		} else {
			return false;
		}
	}
	uint64_t value() {
		return this->deadline;
	}
} CMS_DUENode;

typedef const cms_node<CMS_DUENode>* Const_P_DNode;

class CMS_Due {
    CMS_Due();
    ~CMS_Due();
public:
    CMS_DUENode * pop_due();
	// logic free, change to free list
    int free_due(CMS_DUENode & pnode);
	// after pushing , the list is ordered
    int push_due(uint64_t msgid, uint64_t deadline, bool flag);
private:
	cms_list<CMS_DUENode> *list;
}; // end CMS_Due

#endif /* overdue_h */
