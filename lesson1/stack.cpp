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
		bool push (T newelem); // 进栈 
		bool pop(); // 出栈 
		T top(); // 访问栈元素 
		int size(); // 栈大小 
	private:
		int nsize; 
		T elem[MAXSIZE]; // 存储元素		
};

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


int main(int argc, char** argv) {
	Stack<int> s;
	s.push(3);
	s.push(4);
	s.pop();
	cout << s.top() << endl;
	cout << s.size() << endl;
	system("PAUSE");
}
