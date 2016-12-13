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
		bool push (T newelem); // ��� 
		bool pop(); // ���� 
		T front(); // ���ʶ���Ԫ�أ��������� 
		int size(); // ���д�С 
	private:
		int head,tail; // ��ͷ����β���±� 
		T elem[MAXSIZE]; // �洢	
};

// ���캯�� 
template <class T>  
Queue<T>::Queue() {  
	head = tail = 0;
}

//��������  
template <class T>  
Queue<T>::~Queue() {  
    delete[] elem;  
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


int main(int argc, char** argv) {
	Queue<int> s;
	s.push(3);
	s.push(4);
	s.pop();
	cout << s.front() << endl;
	cout << s.size() << endl;
	system("PAUSE");
}

