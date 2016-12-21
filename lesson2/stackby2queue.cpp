#include <iostream>
#include <queue>

using namespace std;

/**
����
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


// ��ջ
template <class T>  
void Stack<T>::push(T newelem) {
	// ��ջ��ʱ���¼��ջ��Ԫ�� 
	top_record = newelem;
	if (q1.size() != 0)// �ж�������q1����q2
		q1.push(newelem);
	else
		q2.push(newelem);
	return ;	
}

// ��ջ 
template <class T>  
void Stack<T>::pop() {
	if (q1.size() != 0) {// �ж�������q1����q2
		if (q1.size() <= 1) top_record = NULL;
		while (q1.size() > 1) {// q1ת�Ƶ�q2�������ڶ���Ϊջ����������һ������ 
			// ջ��ʱ���¼��ջ��Ԫ�� 
			if(q1.size() == 2) top_record = q1.front(); 
			q2.push(q1.front());
			q1.pop();
		}
		q1.pop();
	} else {
		if (q2.size() <= 1) top_record = NULL;
		while (q2.size() > 1) {// q2ת�Ƶ�q1
			if(q2.size() == 2) top_record = q2.front(); 
			q1.push(q2.front());
			q2.pop();
		}
		q2.pop();
	}	
}

// ջ��Ԫ�أ��򵥴������쳣 
template <class T>  
T Stack<T>::top() {	
	if(top_record == NULL) {
		throw -99999; 
	} else {
		return top_record;
	}
}

// ��С 
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
