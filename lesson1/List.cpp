#include <iostream>
#include "list.h"

// 构造函数 
template <class T>  
List<T>::List() {  
	node = NULL;
	nsize = 0;
}

//析构函数  
template <class T>  
List<T>::~List() {  
	for (int i = 0 ; i < nsize;i ++) {
		ListNode<T> *tmp = node;
		node = node->next;
		delete tmp;
	}
}

// 从头插入
template <class T>  
bool List<T>::push_front(T newelem) {  
	ListNode<T> *tmp = new ListNode<T>; // 新元素
	tmp->value = newelem;
	
	if (nsize) {
		tmp->next = node;
		tmp->pre = node->pre;
		node->pre->next = tmp;
		node->pre = tmp;
	} else {
		node = tmp->next = tmp->pre = tmp; // 空链特殊处理 
	}
	node = tmp; // 新的列表头，去掉这行即得到push_back()
	nsize++; // push都是push到头和尾之间
	return true; 
}

// 从尾插入
template <class T>  
bool List<T>::push_back(T newelem) {  
	ListNode<T> *tmp = new ListNode<T>; // 新元素
	tmp->value = newelem;
	
	if (nsize) {
		tmp->next = node;
		tmp->pre = node->pre;
		node->pre->next = tmp;
		node->pre = tmp;
	} else {
		node = tmp->next = tmp->pre = tmp; // 空链特殊处理 
	}
	nsize++; // push都是push到头和尾之间
	return true; 
}

// 从头弹出 
template <class T>  
bool List<T>::pop_front() {  
	if (!node) return false;
	ListNode<T> *tmp = node; // 把这行改为node->pre即为pop_back()
	tmp->pre->next = tmp->next;
	tmp->next->pre = tmp->pre;
	node = node->next; // 去掉这个为pop_back()
	delete tmp;
	nsize--;
	return true; 
}

// 从尾弹出 
template <class T>  
bool List<T>::pop_back() {  
	if (!node) return false;
	ListNode<T> *tmp = node->pre; // 把这行改为node->pre即为pop_back()
	tmp->pre->next = tmp->next;
	tmp->next->pre = tmp->pre;
	delete tmp;
	nsize--;
	return true; 
}

// 批量删除 
template <class T>  
bool List<T>::remove(ListNode<T> *p1,ListNode<T> *p2) {
	if (!p1 || !p2) return false;
	
	p2->pre = p1->pre;
	p2->pre->next = p2;
	
	while(p1 != p2) {
		if (p1 == node) node=p2; // 如果删除的元素中有node
		ListNode<T> * tmp = p1;
		p1 = p1->next;
		delete tmp;
		nsize--; 
	}

	return true; 
}

// 访问头部 
template <class T>  
ListNode<T> * List<T>::front() {
	return node; 
}

// 访问尾部 
template <class T>  
ListNode<T>* List<T>::back() {
	return node->pre; 
}

// 访问大小 
template <class T>  
int List<T>::size() {
	return nsize; 
}
