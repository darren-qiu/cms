//
//  mlist.h
//  comm_msgsys
//
//  Created by 邱东洋 on 2017/11/30.
//  Copyright © 2017年 darren. All rights reserved.
//

#ifndef _MLIST_H
#define _MLIST_H

#include "mbody.h"

typedef struct mnode {
    CMS_MBody * pMBody;
    mnode * pHead;
    mnode * pTail;
} CMS_MNode;

class CMS_MList {
    CMS_MList();
    ~CMS_MList();
public:
    int set(CMS_MBody&);
    int del(uint64_t);
    CMS_MBody* get(uint64_t);
private:
    int init(int cou);
    int extend(int cou);
    CMS_MNode * init_malloc(int cou);
    int clear();
private:
    map<uint64_t, pMBody> * pM;
    CMS_MNode * pHead;
    CMS_MNode * pTail;
    CMS_MNode * pFreeHead;
    CMS_MNode * pFreeTail;
	int cou;
    int freecou;
}; // end CMS_MList

#endif /* _MLIST_H */
