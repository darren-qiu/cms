//
//  overdue.cpp
//  comm_msgsys
//
//  Created by 邱东洋 on 2017/12/1.
//  Copyright © 2017年 darren. All rights reserved.
//

#include "overdue.h"

CMS_Due::CMS_Due() {
	list = new cms_list<CMS_DUENode>();
}

CMS_Due::~CMS_Due() {
	if(list != NULL) {
		delete list;
		list = NULL;
	}
}

CMS_DUENode* CMS_Due::pop_due() {
	CMS_DUENode *pNode;
	return pNode;
}

int CMS_Due::free_due(CMS_DUENode& node) {
	return 0;
}

int CMS_Due::push_due(uint64_t msgid, uint64_t deadline, bool flag) {
	return 0;
}

