//
//  mlist.h
//  comm_msgsys
//
//  Created by 邱东洋 on 2017/11/30.
//  Copyright © 2017年 darren. All rights reserved.
//

#ifndef mlist_h
#define mlist_h

#include "mbody.h"

class CMS_MList {
    CMS_MList();
    ~CMS_MList();
public:
    int add(CMS_MBody&);
    int del(uint64_t);
    CMS_MBody& find(uint64_t);
private:
    map<uint64_t, pMBody> * pM;
    vector<CMS_MBody> * pV;
}; // end CMS_MList

#endif /* mlist_h */
