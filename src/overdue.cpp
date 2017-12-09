//
//  overdue.cpp
//  comm_msgsys
//
//  Created by 邱东洋 on 2017/12/1.
//  Copyright © 2017年 darren. All rights reserved.
//

#include "overdue.h"

CMS_Due::CMS_Due() {
	this->list = new cms_list<CMS_DUEBody>();
}

CMS_Due::~CMS_Due() {
	if(list != NULL) {
		delete list;
		list = NULL;
	}
}

CMS_Const_P_DNode CMS_Due::begin() {
	return this->list->begin();
}

int CMS_Due::erase(CMS_P_DNode p) {
	return this->list->free_node(p);
}

int CMS_Due::push(CMS_DUEBody &body) {
	this->list->push_sort(body);
	return 0;
}

int CMS_Due::size() {
	return this->list->size();
}

