#include "queue.h"

// ���캯�� 
template <class T>  
Queue<T>::Queue() {  
	head = tail = 0;
}

//��������  
template <class T>  
Queue<T>::~Queue() {  
    delete elem;  
}

// ��� 
template <class T>  
bool Queue<T>::push(T newelem) {  
	if ((tail + 1) % MAXSIZE == head) return false;
	elem[tail] = newelem;
	tail = (tail + 1) % MAXSIZE;
	return true;
}

// ���� 
template <class T>  
bool Queue<T>::pop() {  
	if (head == tail) return false;
	head = (head + 1) % MAXSIZE;
	return true;
}

// ���ʶ�ͷ 
template <class T>  
T Queue<T>::front() {  
	return elem[head];
}

// ���ʶӴ�С
template <class T>  
int Queue<T>::size() {  
	return (MAXSIZE + tail - head) % MAXSIZE; 
}


