//
//  overdue.cpp
//  comm_msgsys
//
//  Created by 邱东洋 on 2017/12/1.
//  Copyright © 2017年 darren. All rights reserved.
//

#include "overdue.h"

CMS_Due::CMS_Due() {
}

CMS_Due::~CMS_Due() {
}

CMS_DueNode* CMS_Due::pop_due() {
	CMS_DueNode * pNode;
	return pNode;
}

int CMS_Due::free_due(CMS_DueNode& node) {
	return 0;
}

int CMS_Due::push_due(uint64_t msgid, uint64_t deadline, bool flag) {
	return 0;
}

int CMS_Due::init_malloc(int count) {
	return 0;
}

int CMS_Due::init(int count) {
	return 0;
}

int CMS_Due::extend(int count) {
	return 0;
}

int CMS_Due::clear() {
	return 0;
}

