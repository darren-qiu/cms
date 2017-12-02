//
//  overdue.h
//  comm_msgsys
//
//  Created by 邱东洋 on 2017/12/1.
//  Copyright © 2017年 darren. All rights reserved.
//

#ifndef overdue_h
#define overdue_h

#include <string>
using namespace std;

typedef struct node {
    node * father;
    node * child;
    uint64_t msgid;
    uint64_t deadline;
    bool flag;
    string mainkey;
} CMS_DueNode;

class CMS_Due {
    CMS_Due();
    ~CMS_Due();
public:
    CMS_DueNode * pop();
    int free(CMS_DueNode & pnode);
    int add(uint64_t msgid, uint64_t deadline, bool flag);
private:
    int init_malloc(int cou);
    int init(int cou);
    int extend(int cou);
    void clear();
private:
    CMS_DueNode * pHead;
	CMS_DueNode * pTail;
    CMS_DueNode * pFreeHead;
	CMS_DueNode * pFreeTail;
    int cou;
	int freecou;
}; // end CMS_Due

#endif /* overdue_h */
