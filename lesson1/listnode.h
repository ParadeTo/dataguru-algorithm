#include <iostream>
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
