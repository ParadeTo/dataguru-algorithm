#include <iostream>
#include <queue>

using namespace std;

/**
链表
**/
template<class T>
class Stack{
public:
    Stack(){top_record=NULL;};
    ~Stack(){};
    void push(T newelem);
    void pop();
    T top();
    int size();
private:
    queue<T> q1,q2;
    T top_record;
};


// 进栈
template <class T>  
void Stack<T>::push(T newelem) {
	// 进栈的时候记录下栈顶元素 
	top_record = newelem;
	if (q1.size() != 0)// 判断数据在q1还是q2
		q1.push(newelem);
	else
		q2.push(newelem);
	return ;	
}

// 出栈 
template <class T>  
void Stack<T>::pop() {
	if (q1.size() != 0) {// 判断数据在q1还是q2
		if (q1.size() <= 1) top_record = NULL;
		while (q1.size() > 1) {// q1转移到q2，倒数第二个为栈顶，倒数第一个弹出 
			// 栈的时候记录下栈顶元素 
			if(q1.size() == 2) top_record = q1.front(); 
			q2.push(q1.front());
			q1.pop();
		}
		q1.pop();
	} else {
		if (q2.size() <= 1) top_record = NULL;
		while (q2.size() > 1) {// q2转移到q1
			if(q2.size() == 2) top_record = q2.front(); 
			q1.push(q2.front());
			q2.pop();
		}
		q2.pop();
	}	
}

// 栈顶元素，简单处理下异常 
template <class T>  
T Stack<T>::top() {	
	if(top_record == NULL) {
		throw -99999; 
	} else {
		return top_record;
	}
}

// 大小 
template <class T>  
int Stack<T>::size() {  
	return max(q1.size(),q2.size());
}


//int main(int argc, char** argv) {
//
//	Stack<int> s;
//	s.push(1);
//	cout << s.top() << endl;
//	s.push(2);
//	s.push(3);
//	cout << s.top() << endl;
//	s.pop();
//	s.push(4);
//	cout << s.top() << endl;
//
//} 
