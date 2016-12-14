#include <iostream>
using namespace std;

template<class T>
class QueueList {
	public:
		QueueList(){}
		~QueueList(){}
		bool push (T newelem){return elem.push_back(newelem);} // ������ 
		bool pop(){return elem.pop_front();} // ������ 
		T front(){return elem.front()->value;} // ���ʶ���Ԫ�� 
		int size(){return elem.size();} // ���д�С 
		bool display(){ // ��ͷ��β������� 
			ListNode<T> * p = elem.front(); // �õ���ͷ
			do {
				cout << p->value << ' ';
				p = p->next;
			} while (p!=elem.front());
			return true;
		}
	private:
		List<T> elem; // �洢Ԫ��		
};
