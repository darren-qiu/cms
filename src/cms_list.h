#ifndef _CMS_LIST_H
#define _CMS_LIST_H

//#define SIZE_INIT_LIST_DF 10
//#define SIZE_EXTD_LIST_DF 10

#include <iostream>
using namespace std;

template<class T>
class cms_node {
public:
	cms_node<T> *prev;
	cms_node<T> *next;
	T data;
	cms_node(T &value) {
		prev = NULL;
		next = NULL;
		data = value;
	}
	~cms_node() {
		if(prev != NULL) {
			//delete prev;
			prev = NULL;
		}
		if(next != NULL) {
			//delete next;
			next = NULL;
		}
	}
}; // end cms_node

template<class T>
class cms_list {
public:
	cms_list() {
		list_head = NULL;
		list_tail = NULL;
		cou_list = 0;
		sort_flag = 0;
	}
	~cms_list() {
		clear();
		if(list_head != NULL) {
			delete list_head;
			list_head = NULL;
		}
		if(list_tail != NULL) {
			delete list_tail;
			list_tail = NULL;
		}
		sort_flag = 0;
	}
public:
	// some functions about the list
	const cms_node<T>* push_top(T& data);
	const cms_node<T>* push_sort(T& data);
	cms_node<T>* begin();
	cms_node<T>* end();
	cms_node<T>* find(T& value);
	int size();
	// some functions about the free list
	int free_node(cms_node<T>* node);	
private:
	cms_node<T>* get_node();
	void put_node(cms_node<T>* p);
	cms_node<T>* create_node(T &value);
	void destroy_node(cms_node<T> *p);
	void clear();
private:
	cms_node<T> *list_head;
	cms_node<T> *list_tail;
	//cms_node<T> *free_head;
	//cms_node<T> *free_tail;
	int cou_list;
	int sort_flag;	// 0: init value, 1: list, 2: sort list.
	//int cou_free;
	static std::allocator< cms_node<T> > alloc;
}; // end cms_list

#endif // _CMS_LIST_H

template<class T>
std::allocator< cms_node<T> > cms_list<T>::alloc;

template<class T>
const cms_node<T>* cms_list<T>::push_top(T& value) {
	if(sort_flag == 2) {
		return NULL;
	} else if(sort_flag == 0) {
		sort_flag = 1;
	}
	
	cms_node<T>* node = create_node(value);
	if(list_head == NULL) {
		list_head = node;
		list_tail = node;
	} else {
		node->next = list_head;
		list_head->prev = node;
		list_head = node;
	}
	
	cou_list++;
	return node;
}

template<class T>
const cms_node<T>* cms_list<T>::push_sort(T& value) {
	if(sort_flag == 1) {
		return NULL;
	} else if(sort_flag == 0) {
		sort_flag = 2;
	}

	cms_node<T>* node = create_node(value);

	if(list_head == NULL) {	
		list_head = node;
		list_tail = node;
	} else {
		cms_node<T>* p = list_head;
		
		while((p->next != NULL) && !(node->data < p->data)) {
			p = p->next;
		}

		if(p->next == NULL) {
			p->next = node;
			node->prev = p;
			node->next = NULL;
			list_tail = node;
		} else if (p->prev == NULL) {
			node->next = p;
			node->prev = NULL;
			p->prev = node;
			list_head = node;
		} else {
			node->next = p;
			node->prev = p->prev;
			p->prev->next = node;
			p->prev = node;
		}
	}
	cou_list++;
	return node;
}

template<class T>
cms_node<T>* cms_list<T>::begin() {
	if(list_head == NULL) {
		return NULL;
	} else {
		return list_head;
	}
}

template<class T>
cms_node<T>* cms_list<T>::end() {
	if(list_tail == NULL) {
		return NULL;
	} else {
		return list_tail;
	}
}

template<class T>
cms_node<T>* cms_list<T>::find(T& value) {
	if(list_head == NULL) {
		return NULL;
	}
	cms_node<T>* p = list_head;
	while(NULL != p->next) {
		if(p->data == value) {
			return p;
		}
		p = p->next;
	}
	if(p->data == value) {
		return p;
	} else {
		return NULL;
	}
}

template<class T>
int cms_list<T>::size() {
	return cou_list;
}

template<class T>
int cms_list<T>::free_node(cms_node<T>* p) {
	if(p == NULL) { 
		return -1; 
	} else if(p == list_head && p == list_tail) { 
		list_head = NULL;
		list_tail = NULL;
	} else if(p == list_head) {
		list_head = p->next;
		list_head->prev = NULL;
	} else if(p == list_tail) {
		list_tail = list_tail->prev;
		list_tail->next = NULL;
	} else {
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}
	destroy_node(p);
	cou_list--;
	return 0;
}

template<class T>
cms_node<T>* cms_list<T>::get_node() {
	return alloc.allocate(1);
}

template<class T>
void cms_list<T>::put_node(cms_node<T> *p) {
	alloc.deallocate(p,1);
}

template<class T>
cms_node<T>* cms_list<T>::create_node(T &value) {
	cms_node<T> *p = get_node();
	//alloc.construct(p,cms_node<T>(value));
	alloc.construct(p,value);
	return p;
}

template<class T>
void cms_list<T>::destroy_node(cms_node<T> *p) {
	alloc.destroy(p);
	put_node(p);
}

template<class T>
void cms_list<T>::clear() {
	cms_node<T> *p = list_head;
	while(p!=list_tail) {
		list_head = p->next;
		destroy_node(p);
		p = list_head;
	}
	if(p != NULL) {
		destroy_node(p);
		list_head = NULL;
		list_tail = NULL;
	}
}

