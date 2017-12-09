#include "mlist.h"

CMS_MList::CMS_MList() {
	plist = new cms_list<CMS_MBody>();
}

CMS_MList::~CMS_MList() {
	if(plist != NULL) {
		delete plist;
		plist = NULL;
	}
}

int CMS_MList::set(CMS_MBody& body) {
	const CMS_MNode *q = plist->push_top(body);
	CMS_MNode *p = const_cast<CMS_MNode*>(q);
	if(NULL == p) {
		return -1;
	} else {
		//cout << "(msgid,p) " << body._msgid << "," << p << endl;
		mlist.insert(map<uint64_t,CMS_MNode*>::value_type(body._msgid,p));
		return 0;
	}
}

// logic delete. and the struct of CMS_MNode must be two-way linked-list because of it 
int CMS_MList::del(uint64_t msgid) {
	//CMS_MNode* p = mlist.at(msgid);
	CMS_MNode* p = mlist[msgid];
	if(p == NULL) { 
		return -1;
	}
	if(0 != plist->free_node(p)) {
		return -2;
	}
	mlist.erase(msgid);
	return 0;
}

CMS_MBody* CMS_MList::get(uint64_t msgid) {
	// if the key that's value is msgid is not exist, how about?
	CMS_MNode *p = mlist[msgid];
	if(p == NULL) {
		return NULL;
	} else {
		return &(p->data);
	}
}

int CMS_MList::size() {
	return plist->size();
}

