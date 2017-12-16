#include "index.h"

int CMS_IDX::set_uri(CMS_MK &mk, CMS_MID mid) {
	//cout << "mk mid " << mk << " " << mid.msgid << endl;
	CMS_MV *mv = &index[mk];
	//cout << "p_un_read_idx size " << mv->p_un_read_idx->size() << endl;
	//cout << (mv->p_un_read_idx) << endl;
	const CMS_Post *p = mv->p_un_read_idx->push_top(mid);
	//cout << "p_un_read_idx size " << mv->p_un_read_idx->size() << endl;
	if(NULL == p) {
		return -1;
	} else {
		return 0;
	}
}

int CMS_IDX::set_rsi(CMS_MK &mk, CMS_MID mid) {
	CMS_MV *mv = &index[mk];
	const CMS_Post *p = mv->p_read_sy_idx->push_top(mid);
	if(NULL == p) {
		return -1;
	} else {
		return 0;
	}
}

int CMS_IDX::get_uri(CMS_MK &mk, vector<CMS_MID>& mid_list) {
	CMS_MV *mv = &index[mk];
	if(NULL == mv->p_un_read_idx) {
		return -1;
	}
	return mv->p_un_read_idx->get_all(mid_list);
}

int CMS_IDX::get_rsi(CMS_MK &mk, vector<CMS_MID>& mid_list) {
	CMS_MV *mv = &index[mk];
	if(NULL == mv->p_read_sy_idx) {
		return -1;
	}
	return mv->p_read_sy_idx->get_all(mid_list);
}

int CMS_IDX::del_uri(CMS_MK &mk, CMS_MID mid) {
	CMS_MV *mv = &index[mk];
	if(NULL == mv->p_un_read_idx) {
		return -1;
	}
	CMS_Post *p = mv->p_un_read_idx->find(mid);
	if(NULL == p) {
		return -2;
	}
	return mv->p_un_read_idx->free_node(p);
}

int CMS_IDX::del_rsi(CMS_MK &mk, CMS_MID mid) {
	CMS_MV *mv = &index[mk];
	if(NULL == mv->p_read_sy_idx) {
		return -1;
	}
	CMS_Post *p = mv->p_read_sy_idx->find(mid);
	if(NULL == p) {
		return -2;
	}
	return mv->p_read_sy_idx->free_node(p);
}

int CMS_IDX::len_uri(CMS_MK &mk) {
	CMS_MV *mv = &index[mk];
	if(NULL == mv->p_un_read_idx) {
		return 0;
	}
	return mv->p_un_read_idx->size();
}

int CMS_IDX::len_rsi(CMS_MK &mk) {
	CMS_MV *mv = &index[mk];
	if(NULL == mv->p_read_sy_idx) {
		return 0;
	}
	return mv->p_read_sy_idx->size();
}

