#ifndef _MLIST_H
#define _MLIST_H

#define SIZE_INIT_CMS_MNODE	1000
#define SIZE_EXTD_CMS_MNODE	1000

#include <map>
#include "mbody.h"

using namespace std;

typedef struct mnode {
    CMS_MBody * pMBody;
    mnode * pHead;
    mnode * pTail;
	mnode() {
		pMBody = NULL;
		pHead = NULL;
		pTail = NULL;
	}
	~mnode() {
		if(pMBody != NULL) {
			delete pMBody;
			pMBody = NULL;
		}
		if(pHead != NULL) {
			delete pHead;
			pHead = NULL;
		}
		if(pTail != NULL) {
			delete pTail;
			pTail = NULL;
		}
	}
} CMS_MNode;

class CMS_MList {
    CMS_MList();
    ~CMS_MList();
public:
    int set(CMS_MBody&);
    int del(uint64_t);
    CMS_MBody* get(uint64_t);
private:
    int init(int cou=SIZE_INIT_CMS_MNODE);
    int extend(int cou=SIZE_EXTD_CMS_MNODE);
    CMS_MNode * init_malloc(int cou);
    int clear();
private:
    map<uint64_t, CMS_MNode*> pMList;
    CMS_MNode * pHead;
    CMS_MNode * pTail;
    CMS_MNode * pFreeHead;
    CMS_MNode * pFreeTail;
	int cou;
    int freecou;
}; // end CMS_MList

#endif /* _MLIST_H */
