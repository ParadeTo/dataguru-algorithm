#include <iostream>
using namespace std;

/**
������ 
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

// ���캯�� 
template <class T>  
ListNode<T>::ListNode() {  
	next = pre = NULL;
}

//��������  
template <class T>  
ListNode<T>::~ListNode() {  

}
