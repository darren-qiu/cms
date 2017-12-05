#ifndef _CMS_LIST_H
#define _CMS_LIST_H

#define SIZE_INIT_LIST_DF 1000
#define SIZE_EXTD_LIST_DF 1000

template<class T>
class cms_node {
public:
	cms_node<T> *prev;
	cms_node<T> *next;
	T data;
}; // end cms_node

template<class T>
class cms_list {
	cms_list() {
		init_node();
	}
	~cms_list() {
		clear();
	}
public:
	// some functions about the list
	cms_node<T>* push_top(const T& data);
	cms_node<T>* push_sort(const T& data);
	cms_node<T>* pop_top();
	// some functions about the free list
	int free_node(cms_node<T>* node);	
private:
	//cms_node<T>* new_node();
	cms_node<T>* malloc_node(int count);
	int init_node(int count=SIZE_INIT_LIST_DF);
	int extd_node(int count=SIZE_EXTD_LIST_DF);
	int clear();
private:
	cms_node<T> *list_head;
	cms_node<T> *list_tail;
	cms_node<T> *free_head;
	cms_node<T> *free_tail;
	int cou_list;
	int cou_free;
}; // end cms_list

#endif // _CMS_LIST_H

