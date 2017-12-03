#ifndef _COMM_MSG_SYS_H
#define _COMM_MSG_SYS_H

#include <vector>
#include <string>
#include "index.h"
#include "mlist.h"
#include "cache.h"
#include "overdue.h"

using namespace std;

typedef struct cond {
	char type;
	char channel;
	int start;
	int count;
	bool read;
} CMS_Cond;

class CMS {
public:
	int SendMsgToUser(CMS_MainKey& mk,CMS_MBody& mb);
	int BroadCast(CMS_MainKey& mk,CMS_MBody& mb);
	int GetUserMsg(CMS_MainKey& mk,CMS_Cond& cd,vector<CMS_MBody>& msg);
	int CouUserUnReadMsg(CMS_MainKey& mk);
private:
	CMS_Index * pIndex;
	CMS_Cache * pCache;
	CMS_MList * pMList;
	CMS_Due * pDueList;
}; // end CMS

#endif // _COMM_MSG_SYS_H

