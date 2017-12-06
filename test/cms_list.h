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
	cms_node() {
		prev = NULL;
		next = NULL;
	}
	~cms_node() {
		if(prev != NULL) {
			delete prev;
			prev = NULL;
		}
		if(next != NULL) {
			delete next;
			next = NULL;
		}
	}
}; // end cms_node

template<class T>
class cms_list {
public:
	cms_list() {
		init_node();
	}
	~cms_list() {
		cout << "~cms_list() start" << endl;
		clear();
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
	static std::allocator< cms_node<T> > alloc;
}; // end cms_list

#endif // _CMS_LIST_H

//#include <stdio.h>
//#include "cms_list.h"

template<class T>
cms_node<T>* cms_list<T>::push_top(const T& data) {
	cms_node<T>* node = get_node();
	node->data = data;
	if(list_head == NULL) {
		list_head = node;
		list_tail = node;
	} else {
		node->next = list_head;
		list_head = node;
	}
	return node;
}

template<class T>
cms_node<T>* cms_list<T>::push_sort(const T& data) {
	cms_node<T>* node = get_node();
	node->data = data;
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
int cms_list<T>::free_node(cms_node<T>* node) {
	if(list_head == node && list_tail == node) {
		// if there is only one node
		list_head = NULL;
		list_tail = NULL;
	} else if(list_head == node) {
		// if the node is head node
		list_head = node->next;
		node->next->prev = NULL;
	} else if(list_tail == node) {
		// if the node is tail node
		list_tail = node->prev;
		node->prev->next = NULL;
	} else {
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}
	if(free_tail == NULL) {
		// if free list is null
		free_head = node;
		free_tail = node;
		node->prev = NULL;
		node->next = NULL;
	} else {
		free_tail->next = node;
		node->prev = free_tail;
		free_tail = node;
		node->next = NULL;
	}
	return 0;
}

template<class T>
cms_node<T>* cms_list<T>::get_node() {
	if(free_head == NULL) {
		extd_node();
	}
	cms_node<T>* node = free_head;
	free_head = node->next;
	free_head->prev = NULL;
	node->next = NULL;
	return node;
}

template<class T>
cms_node<T>* cms_list<T>::malloc_node(int count) {
	cms_node<T>* node = new cms_node<T>[count];
	cms_node<T>* p = &node[0];
	cout << "p0 " << p << endl;
	p->prev = NULL;
	p->next = &node[1];
	for(unsigned int i=1; i<count-1; i++) {
		p = &node[i];
		cout << "p" << i << " " << p << endl;
		p->prev = &node[i-1];
		p->next = &node[i+1];
	}
	p->next->prev = p;
	p->next->next = NULL;
	return node;
}

template<class T>
int cms_list<T>::init_node(int count) {
	cout << "init_node" << endl;
	list_head = NULL;
	list_tail = NULL;
	cou_list = 0;
	cms_node<T>* node = malloc_node(count);
	free_head = node;
	free_tail = &node[count-1];
	cou_free = count;
	return 0;
}

template<class T>
int cms_list<T>::extd_node(int count) {
	cms_node<T>* node = malloc_node(count);
	free_tail->next = node;
	node->prev = free_tail;
	free_tail = &node[count-1];
	cou_free += count;
	return 0;
}

template<class T>
int cms_list<T>::clear() {
	cout << "clear" << endl;
	int del_cou = 0, del_free_cou = 0;
	cms_node<T>* p;

	cout << "delete list " << endl;
	while(list_head != list_tail) {
		p = list_head;
		list_head = p->next;
		if(p != NULL) {
			delete p;
			p = NULL;
			del_cou++;
		}
	}
	if(list_head != NULL) {
		delete list_head;
		list_head = NULL;
		del_cou++;
	}

	cout << "delete free list " << endl;
	while(free_head != free_tail) {
		cout << "free_head " << free_head << endl;
		cout << "free_tail " << free_tail << endl;
		p = free_head;
		cout << "p=free_head " << p << endl;
		free_head = p->next;
		cout << "p->next " << free_head << endl;
		if(p != NULL) {
			cout << "p " << p << endl;
			delete p;
			cout << "delete p" << endl;
			p = NULL;
			del_free_cou++;
			cout << "delete p complite" << endl;
		}
	}
	cout << "delete the last node in free list" << endl;
	if(free_head != NULL) {
		delete free_head;
		free_head = NULL;
		del_free_cou++;
	}
	cout << "clear end" << endl;
	return 0;
}

//template class cms_list<int>;

