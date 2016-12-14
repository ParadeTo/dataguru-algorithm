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

