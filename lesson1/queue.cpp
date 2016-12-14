#include "queue.h"

// 构造函数 
template <class T>  
Queue<T>::Queue() {  
	head = tail = 0;
}

//析构函数  
template <class T>  
Queue<T>::~Queue() {  
    delete elem;  
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


