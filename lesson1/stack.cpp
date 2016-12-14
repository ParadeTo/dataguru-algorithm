#include "stack.h"

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
