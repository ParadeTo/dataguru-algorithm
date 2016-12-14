#include <iostream>
using namespace std;

template<class T>
class QueueList {
	public:
		QueueList(){}
		~QueueList(){}
		bool push (T newelem){return elem.push_back(newelem);} // 进队列 
		bool pop(){return elem.pop_front();} // 出队列 
		T front(){return elem.front()->value;} // 访问队首元素 
		int size(){return elem.size();} // 队列大小 
		bool display(){ // 从头到尾输出队列 
			ListNode<T> * p = elem.front(); // 得到链头
			do {
				cout << p->value << ' ';
				p = p->next;
			} while (p!=elem.front());
			return true;
		}
	private:
		List<T> elem; // 存储元素		
};
