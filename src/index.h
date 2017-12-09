#ifndef _INDEX_H
#define _INDEX_H

#include <string>
#include <vector>
#include <map>
#include "cms_list.h"

using namespace std;

typedef uint64_t CMS_MID;
typedef cms_node<uint64_t> CMS_Post;
typedef cms_list<uint64_t> CMS_Posting;
typedef string CMS_MK;

typedef class cms_mvalue {
public:
	cms_mvalue() {
		p_un_read_idx = new CMS_Posting();
		p_read_sy_idx = new CMS_Posting();
	}
	~cms_mvalue() {
		if(p_un_read_idx != NULL) {
			delete p_un_read_idx;
			p_un_read_idx = NULL;
		}
		if(p_read_sy_idx != NULL) {
			delete p_read_sy_idx;
			p_read_sy_idx = NULL;
		}
	}
public:
	CMS_Posting * p_un_read_idx;
	CMS_Posting * p_read_sy_idx;
} CMS_MV;

class CMS_IDX {
public:
	int set_uri(CMS_MK &mk, CMS_MID mid);
	int set_rsi(CMS_MK &mk, CMS_MID mid);
	int get_uri(CMS_MK &mk, vector<CMS_MID>& mid_list);
	int get_rsi(CMS_MK &mk, vector<CMS_MID>& mid_list);
	int del_uri(CMS_MK &mk, CMS_MID mid);
	int del_rsi(CMS_MK &mk, CMS_MID mid);
	int len_uri(CMS_MK &mk);
	int len_rsi(CMS_MK &mk);
private:
	map<CMS_MK,CMS_MV> index;
}; // end CMS_Index

#endif // _POSTING_H

