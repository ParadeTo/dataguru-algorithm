#ifndef __SOMEFILE_H__
#define __SOMEFILE_H__
#define MAXSIZE 10
using namespace std;

template<class T>
class Queue {
	public:
		Queue();
		~Queue();
		bool push (T newelem); // 入队 
		bool pop(); // 出队 
		T front(); // 访问队首元素，不出队列 
		int size(); // 队列大小 
	private:
		int head,tail; // 队头，队尾的下标 
		T elem[MAXSIZE]; // 存储	
};

#endif
