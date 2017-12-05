#include <stdio.h>
#include "cms_list.h"

template<class T>
cms_node<T>* cms_list<T>::push_top(const T& data) {
	cms_node<T>* node = free_head;
	return node;
}

template<class T>
cms_node<T>* cms_list<T>::push_sort(const T& data) {
	cms_node<T>* node = free_head;
	return node;
}

template<class T>
cms_node<T>* cms_list<T>::pop_top() {
	cms_node<T>* node = list_head;
	return node;
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
cms_node<T>* cms_list<T>::malloc_node(int count) {
	cms_node<T>* node = new cms_node<T>[count];
	cms_node<T>* p = &node[0];
	p->prev = NULL;
	p->next = &node[1];
	for(unsigned int i=1; i<count-1; i++) {
		p = &node[i];
		p->prev = &node[i-1];
		p->next = &node[i+1];
	}
	p->next->prev = p;
	p->next->next = NULL;
	return node;
}

template<class T>
int cms_list<T>::init_node(int count) {
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
	int del_cou = 0, del_free_cou = 0;
	cms_node<T>* p;

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

	while(free_head != free_tail) {
		p = free_head;
		free_head = p->next;
		if(p != NULL) {
			delete p;
			p = NULL;
			del_free_cou++;
		}
	}
	if(free_head != NULL) {
		delete free_head;
		free_head = NULL;
		del_free_cou++;
	}
	return 0;
}

template class cms_list<int>;

