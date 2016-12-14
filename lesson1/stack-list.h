using namespace std;

template<class T>
class StackList {
	public:
		StackList(){}
		~StackList(){}
		bool push (T newelem){elem.push_front(newelem);} // 进栈 
		bool pop(){elem.pop_front();} // 出栈 
		T top(){return elem.front()->value;} // 访问栈元素 
		int size(){return elem.size();} // 栈大小 
	private:
		List<T> elem; // 存储元素		
};

