#ifndef _CMS_LIST_H
#define _CMS_LIST_H

#define SIZE_INIT_LIST_DF 10
#define SIZE_EXTD_LIST_DF 10

#include <iostream>

using namespace std;

template<class T>
class cms_node {
public:
	cms_node<T> *prev;
	cms_node<T> *next;
	T data;
	cms_node(const T &value) {
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
	}
	~cms_list() {
		cout << "~cms_list() start" << endl;
		clear();
		if(list_head != NULL) {
			delete list_head;
			list_head = NULL;
		}
		if(list_tail != NULL) {
			delete list_tail;
			list_tail = NULL;
		}
		cout << "~cms_list() end" << endl;
	}
public:
	// some functions about the list
	cms_node<T>* push_top(const T& data);
	cms_node<T>* push_sort(const T& data);
	cms_node<T>* pop_top();
	int size();
	// some functions about the free list
	int free_node(cms_node<T>* node);	
private:
	cms_node<T>* get_node();
	void put_node(cms_node<T>* p);
	cms_node<T>* create_node(const T &value);
	void destroy_node(cms_node<T> *p);
	void clear();
private:
	cms_node<T> *list_head;
	cms_node<T> *list_tail;
	//cms_node<T> *free_head;
	//cms_node<T> *free_tail;
	int cou_list;
	//int cou_free;
	static std::allocator< cms_node<T> > alloc;
}; // end cms_list

#endif // _CMS_LIST_H

//#include <stdio.h>
//#include "cms_list.h"

template<class T>
cms_node<T>* cms_list<T>::push_top(const T& value) {
	cms_node<T>* node = create_node(value);
	if(list_head == NULL) {
		list_head = node;
		list_tail = node;
	} else {
		node->next = list_head;
		list_head = node;
	}
	cou_list++;
	return node;
}

template<class T>
cms_node<T>* cms_list<T>::push_sort(const T& value) {
	cms_node<T>* node = create_node(value);
	if(list_head == NULL) {	
		list_head = node;
		list_tail = node;
	} else {
		cms_node<T>* p = list_head;
		while(!(node->data < p->data)) {
			p = p->next;
		}
		node->next = p;
		node->prev = p->prev;
		p->prev->next = node;
		p->prev = node;
	}
	cou_list++;
	return node;
}

template<class T>
cms_node<T>* cms_list<T>::pop_top() {
	if(list_head == NULL) {
		return NULL;
	} else {
		return list_head;
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
cms_node<T>* cms_list<T>::create_node(const T &value) {
	cms_node<T> *p = get_node();
	//alloc.construct(&(p->data), value);
	alloc.construct(p,cms_node<T>(value));
	return p;
}

template<class T>
void cms_list<T>::destroy_node(cms_node<T> *p) {
	cout << "destroy node " << endl;
	//alloc.destroy(&(p->data));
	alloc.destroy(p);
	cout << "destroy ... " << endl;
	put_node(p);
	cout << "put node " << endl;
}

template<class T>
void cms_list<T>::clear() {
	cout << "clear start" << endl;
	cms_node<T> *p = list_head;
	while(p!=list_tail) {
		cout << "p " << p << endl;
		list_head = p->next;
		destroy_node(p);
		p = list_head;
	}
	cout << "p - " << p << endl;
	if(p != NULL) {
		destroy_node(p);
		list_head = NULL;
		list_tail = NULL;
	}
}

//template class cms_list<int>;

