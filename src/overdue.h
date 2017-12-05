//
//  overdue.h
//  comm_msgsys
//
//  Created by 邱东洋 on 2017/12/1.
//  Copyright © 2017年 darren. All rights reserved.
//

#ifndef overdue_h
#define overdue_h

#define SIZE_INIT_OVERDUE_LEN 1000
#define SIZE_EXTD_OVERDUE_LEN 1000

#include <string>
using namespace std;

typedef struct duenode {
    duenode * pHead;
    duenode * pTail;
    uint64_t msgid;
    uint64_t deadline;
    bool flag;
    string mainkey;
	duenode() {
		pHead = NULL;
		pTail = NULL;
		msgid = 0;
		deadline = 0;
		flag = false;
		mainkey = "";
	}
	~duenode() {
		if(pHead != NULL) {
			delete pHead;
			pHead = NULL;
		}
		if(pTail != NULL) {
			delete pTail;
			pTail = NULL;
		}
	}
} CMS_DueNode;

class CMS_Due {
    CMS_Due();
    ~CMS_Due();
public:
    CMS_DueNode * pop_due();
	// logic free, change to free list
    int free_due(CMS_DueNode & pnode);
	// after pushing , the list is ordered
    int push_due(uint64_t msgid, uint64_t deadline, bool flag);
private:
    int init_malloc(int cou);
    int init(int cou=SIZE_INIT_OVERDUE_LEN);
    int extend(int cou=SIZE_EXTD_OVERDUE_LEN);
    int clear();
private:
    CMS_DueNode * pHead;
	CMS_DueNode * pTail;
    CMS_DueNode * pFreeHead;
	CMS_DueNode * pFreeTail;
    int cou;
	int freecou;
}; // end CMS_Due

#endif /* overdue_h */
