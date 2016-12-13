/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <iostream>
#include <stdlib.h>
#define MAXSIZE 10
using namespace std;

template<class T>
class Stack {
	public:
		Stack();
		~Stack();
		bool push (T newelem); // ��ջ 
		bool pop(); // ��ջ 
		T top(); // ����ջԪ�� 
		int size(); // ջ��С 
	private:
		int nsize; 
		T elem[MAXSIZE]; // �洢Ԫ��		
};

// ���캯�� 
template <class T>  
Stack<T>::Stack() {  
	this->nsize = 0;
}

//��������  
template <class T>  
Stack<T>::~Stack() {  
    delete[] elem;  
}

// ��ջ
template <class T>  
bool Stack<T>::push(T newelem) {  
	if (this->nsize == MAXSIZE) return false;
	this->elem[this->nsize++] = newelem;
	return true;
}

// ��ջ
template <class T>  
bool Stack<T>::pop() {  
	if (this->nsize == 0) return false;
	this->nsize--;
	return true;
}

// ����ջ�� 
template <class T>  
T Stack<T>::top() {  
	return this->elem[this->nsize-1];
}

// ����ջ��С
template <class T>  
int Stack<T>::size() {  
	return this->nsize;
}


int main(int argc, char** argv) {
	Stack<int> s;
	s.push(3);
	s.push(4);
	s.pop();
	cout << s.top() << endl;
	cout << s.size() << endl;
	system("PAUSE");
}
