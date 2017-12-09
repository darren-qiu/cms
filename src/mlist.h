#ifndef _MLIST_H
#define _MLIST_H

#define SIZE_INIT_CMS_MNODE	1000
#define SIZE_EXTD_CMS_MNODE	1000

#include <map>
#include "mbody.h"

typedef cms_node<CMS_MBody> CMS_MNode;

using namespace std;

class CMS_MList {
public:
    CMS_MList();
    ~CMS_MList();
public:
    int set(CMS_MBody&);
    int del(uint64_t);
    CMS_MBody* get(uint64_t);
	int size();
private:
    map<uint64_t, CMS_MNode*> mlist;
	cms_list<CMS_MBody> *plist;
}; // end CMS_MList

#endif /* _MLIST_H */
