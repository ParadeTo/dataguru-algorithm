#include <iostream>
#include "listnode.h"
#define MAXSIZE 10

using namespace std;

/**
����
**/
template<class T>
class List {
	public:
		List();
		~List();
		bool push_front(T newelem); // ��ǰ���� 
		bool push_back(T newelem); // �Ӻ���� 
		bool insert(ListNode<T> *p, T newelem); // ��pλ�ò���Ԫ�� 
		bool pop_front(); // ������λԪ��
		bool pop_back(); // ����ĩβԪ��
		bool remove(ListNode<T> *p1, ListNode<T> *p2); // ɾ��[p1, p2) ֮�������Ԫ�� 
		ListNode<T>* front(); // ������λ��� 
		ListNode<T>* back(); // ����ĩβ���
		int size(); // ����Ԫ�ظ��� 
	
	private:
		ListNode<T> * node; // ��ͷ
		int nsize; // �����С 
		
};


