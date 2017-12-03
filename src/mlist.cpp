#include "mlist.h"

CMS_MList::CMS_MList() {
	init();
}

CMS_MList::~CMS_MList() {
	clear();
}

int CMS_MList::set(CMS_MBody& body) {
	if(this->pFreeHead == this->pFreeTail) {
		extend();
	}

	CMS_MNode* pNode = this->pFreeHead;
	this->pFreeHead = pNode->pTail;
	this->pFreeHead->pHead = NULL;
	
	pNode->pMBody = new CMS_MBody(body);
	this->pHead->pHead = pNode;
	pNode->pTail = this->pHead;
	this->pHead = pNode;

	pMList.insert(map<uint64_t,CMS_MNode*>::value_type(body._msgid,pNode));

	return 0;
}

// logic delete. and the struct of CMS_MNode must be two-way linked-list because of it 
int CMS_MList::del(uint64_t msgid) {
	CMS_MNode* pNode = this->pMList[msgid];
	if(pNode == NULL) {
		return -1;
	}

	pNode->pTail->pHead = pNode->pHead;
	pNode->pHead->pTail = pNode->pTail;

	pNode->pHead = this->pFreeTail;
	pNode->pTail = NULL;
	this->pFreeTail = pNode;

	delete pNode->pMBody;
	pNode->pMBody = NULL;
	this->pMList.erase(msgid);

	return 0;
}

CMS_MBody* CMS_MList::get(uint64_t msgid) {
	// if the key that's value is msgid is not exist, how about?
	CMS_MNode* pNode = this->pMList[msgid];
	return pNode->pMBody;
}

int CMS_MList::init(int count) {
	this->pHead = NULL;
	this->pTail = NULL;
	this->cou = 0;

	CMS_MNode * pNode = init_malloc(count);
	this->pFreeHead = pNode;
	this->pFreeTail = &pNode[count-1];
	this->freecou = count;

	return 0;
}

int CMS_MList::extend(int count) {
	CMS_MNode * pNode = init_malloc(count);
	this->pFreeTail->pTail = pNode;
	pNode->pHead = this->pFreeTail;
	this->pFreeTail = &pNode[count-1];
	this->freecou += count;
	return 0;
}

CMS_MNode* CMS_MList::init_malloc(int cou) {
	CMS_MNode * p;
	CMS_MNode * pNode = new CMS_MNode[cou];
	p = &pNode[0];
	p->pHead = NULL;
	p->pTail = &pNode[1];
	for(unsigned int i=1; i<cou-1; i++) {
		p = &pNode[i];
		p->pHead = &pNode[i-1];
		p->pTail = &pNode[i+1];
	}
	p->pTail->pHead = p;
	p->pTail->pTail = NULL;
	return pNode;
}

int CMS_MList::clear() {
	int del_cou = 0, del_free_cou = 0;
	CMS_MNode * p;

	while(this->pFreeHead != this->pFreeTail) {
		p = this->pFreeHead;
		this->pFreeHead = p->pTail;
		delete p->pMBody;
		p->pMBody = NULL;
		delete p;
		del_free_cou++;
	}
	delete pFreeHead->pMBody;
	pFreeHead->pMBody = NULL;
	delete pFreeHead;
	pFreeHead = NULL;
	del_free_cou++;

	while(this->pHead != this->pTail) {
		p = this->pHead;
		this->pHead = p->pTail;
		delete p->pMBody;
		p->pMBody = NULL;
		delete p;
		del_cou++;
	}
	delete pHead->pMBody;
	pHead->pMBody = NULL;
	delete pHead;
	pHead = NULL;
	del_cou++;

	if(del_cou == this->cou && del_free_cou == this->freecou) {
		return 0;
	} else if(del_cou == this->cou) {
		return -1;
	} else if(del_free_cou == this->freecou) {
		return -2;
	} else {
		return -3;
	}
}

