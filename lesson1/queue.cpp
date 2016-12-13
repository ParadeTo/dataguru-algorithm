/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <iostream>
#include <stdlib.h>
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

// 构造函数 
template <class T>  
Queue<T>::Queue() {  
	head = tail = 0;
}

//析构函数  
template <class T>  
Queue<T>::~Queue() {  
    delete[] elem;  
}

// 入队 
template <class T>  
bool Queue<T>::push(T newelem) {  
	if ((tail + 1) % MAXSIZE == head) return false;
	elem[tail] = newelem;
	tail = (tail + 1) % MAXSIZE;
	return true;
}

// 出队 
template <class T>  
bool Queue<T>::pop() {  
	if (head == tail) return false;
	head = (head + 1) % MAXSIZE;
	return true;
}

// 访问队头 
template <class T>  
T Queue<T>::front() {  
	return elem[head];
}

// 访问队大小
template <class T>  
int Queue<T>::size() {  
	return (MAXSIZE + tail - head) % MAXSIZE; 
}


int main(int argc, char** argv) {
	Queue<int> s;
	s.push(3);
	s.push(4);
	s.pop();
	cout << s.front() << endl;
	cout << s.size() << endl;
	system("PAUSE");
}

