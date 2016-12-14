#include "stack.h"

// 构造函数 
template <class T>  
Stack<T>::Stack() {  
	this->nsize = 0;
}

//析构函数  
template <class T>  
Stack<T>::~Stack() {  
    delete[] elem;  
}

// 进栈
template <class T>  
bool Stack<T>::push(T newelem) {  
	if (this->nsize == MAXSIZE) return false;
	this->elem[this->nsize++] = newelem;
	return true;
}

// 出栈
template <class T>  
bool Stack<T>::pop() {  
	if (this->nsize == 0) return false;
	this->nsize--;
	return true;
}

// 访问栈顶 
template <class T>  
T Stack<T>::top() {  
	return this->elem[this->nsize-1];
}

// 访问栈大小
template <class T>  
int Stack<T>::size() {  
	return this->nsize;
}
