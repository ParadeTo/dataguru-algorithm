/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <iostream>
#include <stdlib.h>
using namespace std;

/**
链表结点 
**/
template<class T>
class ListNode {
	public:
		ListNode();
		~ListNode();
		T value;
		ListNode<T> *next;
		ListNode<T> *pre;
		
};

// 构造函数 
template <class T>  
ListNode<T>::ListNode() {  
	next = pre = NULL;
}

//析构函数  
template <class T>  
ListNode<T>::~ListNode() {  

}

/**
链表
**/
template<class T>
class List {
	public:
		List();
		~List();
		bool push_front(T newelem); // 从前插入 
		bool push_back(T newelem); // 从后插入 
		bool insert(ListNode<T> *p, T newelem); // 从p位置插入元素 
		bool pop_front(); // 弹出首位元素
		bool pop_back(); // 弹出末尾元素
		bool remove(ListNode<T> *p1, ListNode<T> *p2); // 删除[p1, p2) 之间的所有元素 
		ListNode<T>* front(); // 返回首位结点 
		ListNode<T>* back(); // 返回末尾结点
		int size(); // 返回元素个数 
	
	private:
		ListNode<T> * node; // 链头
		int nsize; // 链表大小 
		
};


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

int main(int argc, char** argv) {
	List<int> a;

	for (int i=10;i<16;i++)
		a.push_back(i);
	
	ListNode<int> *p = a.front();
	
	for (int i=0;i<a.size();i++,p=p->next) printf("%d \t",p->value);
	
	printf("\n");
	
	a.remove(a.front(),a.front()->next->next->next);
	
	p = a.front();
	
	for (int i=0;i<a.size();i++,p=p->next) printf("%d \t",p->value);
	
	printf("\nsize:%d",a.size());
}

