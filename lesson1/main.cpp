#include <iostream>

#include "stack.cpp"
#include "queue.cpp"
#include "list.cpp"
#include "stack-list.h"
#include "queue-list.h"


int main(int argc, char** argv) {
	cout << "-----test stack-----" << endl;
	Stack<int> a;
	a.push(10);
	a.push(11);
	cout << "size :" << a.size();
	cout << "\ntop elem:" << a.top();
	a.pop();
	cout << "\nsize :" << a.size();
	cout << "\ntop elem:" << a.top();
	a.pop(); 
	
	cout << "-----test queue-----" << endl;
	Queue<int> q;
	q.push(10);
	q.push(11);
	cout << "size :" << q.size();
	cout << "\ntop elem:" << q.front();
	q.pop();
	cout << "\nsize :" << q.size();
	cout << "\ntop elem:" << q.front();
	q.pop();
	
	cout << "-----test list-----" << endl;
	List<int> l;

	for (int i=10;i<16;i++)
		l.push_back(i);
	
	ListNode<int> *p = l.front();
	
	for (int i=0;i<l.size();i++,p=p->next) printf("%d ",p->value);
	
	printf("\n");
	l.remove(l.front(),l.front()->next->next->next);
	
	p = l.front();
	
	for (int i=0;i<l.size();i++,p=p->next) printf("%d ",p->value);
	printf("\n");
	printf("\nsize:%d",l.size());
	return 0;
}
