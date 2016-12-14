#include <iostream>
#include "listnode.h"
#define MAXSIZE 10

using namespace std;

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


