#ifndef _INDEX_H
#define _INDEX_H

#include <string>
#include "cache.h"

#define POSTING_MAX_LEN	1024

typedef struct posting {
	CMS_Post * pUnReadHead;
	CMS_Post * pUnReadTail;
	CMS_Post * pReadSysHead;
	CMS_Post * pReadSysTail;
	int couUnRead;
	int couReadSys;
} CMS_Posting;

typedef string CMS_MainKey;

class CMS_Index {
public:
	int add_unread_msg(CMS_MainKey& mk, uint64_t msgid);
	int add_readsys_msg(CMS_MainKey& mk, uint64_t msgid);
	int del_unread_msg(CMS_MainKey& mk, uint64_t msgid);
	int get_unread_cou(CMS_MainKey& mk);
	int get_unread_list(CMS_MainKey& mk,int start,int count,vector<uint64_t>& msgid_list);
private:
	map<CMS_MainKey,CMS_Posting> index;
}; // end CMS_Index

#endif // _POSTING_H

