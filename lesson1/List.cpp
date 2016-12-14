#include <iostream>
#include "list.h"

// ���캯�� 
template <class T>  
List<T>::List() {  
	node = NULL;
	nsize = 0;
}

//��������  
template <class T>  
List<T>::~List() {  
	for (int i = 0 ; i < nsize;i ++) {
		ListNode<T> *tmp = node;
		node = node->next;
		delete tmp;
	}
}

// ��ͷ����
template <class T>  
bool List<T>::push_front(T newelem) {  
	ListNode<T> *tmp = new ListNode<T>; // ��Ԫ��
	tmp->value = newelem;
	
	if (nsize) {
		tmp->next = node;
		tmp->pre = node->pre;
		node->pre->next = tmp;
		node->pre = tmp;
	} else {
		node = tmp->next = tmp->pre = tmp; // �������⴦�� 
	}
	node = tmp; // �µ��б�ͷ��ȥ�����м��õ�push_back()
	nsize++; // push����push��ͷ��β֮��
	return true; 
}

// ��β����
template <class T>  
bool List<T>::push_back(T newelem) {  
	ListNode<T> *tmp = new ListNode<T>; // ��Ԫ��
	tmp->value = newelem;
	
	if (nsize) {
		tmp->next = node;
		tmp->pre = node->pre;
		node->pre->next = tmp;
		node->pre = tmp;
	} else {
		node = tmp->next = tmp->pre = tmp; // �������⴦�� 
	}
	nsize++; // push����push��ͷ��β֮��
	return true; 
}

// ��ͷ���� 
template <class T>  
bool List<T>::pop_front() {  
	if (!node) return false;
	ListNode<T> *tmp = node; // �����и�Ϊnode->pre��Ϊpop_back()
	tmp->pre->next = tmp->next;
	tmp->next->pre = tmp->pre;
	node = node->next; // ȥ�����Ϊpop_back()
	delete tmp;
	nsize--;
	return true; 
}

// ��β���� 
template <class T>  
bool List<T>::pop_back() {  
	if (!node) return false;
	ListNode<T> *tmp = node->pre; // �����и�Ϊnode->pre��Ϊpop_back()
	tmp->pre->next = tmp->next;
	tmp->next->pre = tmp->pre;
	delete tmp;
	nsize--;
	return true; 
}

// ����ɾ�� 
template <class T>  
bool List<T>::remove(ListNode<T> *p1,ListNode<T> *p2) {
	if (!p1 || !p2) return false;
	
	p2->pre = p1->pre;
	p2->pre->next = p2;
	
	while(p1 != p2) {
		if (p1 == node) node=p2; // ���ɾ����Ԫ������node
		ListNode<T> * tmp = p1;
		p1 = p1->next;
		delete tmp;
		nsize--; 
	}

	return true; 
}

// ����ͷ�� 
template <class T>  
ListNode<T> * List<T>::front() {
	return node; 
}

// ����β�� 
template <class T>  
ListNode<T>* List<T>::back() {
	return node->pre; 
}

// ���ʴ�С 
template <class T>  
int List<T>::size() {
	return nsize; 
}
