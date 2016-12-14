#ifndef __SOMEFILE_H__
#define __SOMEFILE_H__
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

#endif
