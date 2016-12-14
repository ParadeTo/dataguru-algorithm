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

