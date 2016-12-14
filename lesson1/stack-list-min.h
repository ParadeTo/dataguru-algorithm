using namespace std;

template<class T>
class StackList {
	public:
		StackList(){}
		~StackList(){}
		bool push (T newelem){// 进栈 
			elem.push_front(newelem);
			if (min_record.size() == 0) min_record.push_front(newelem);
			else {
				T tmp = min_record.front()->value;
				if (newelem < tmp) tmp = newelem;
				min_record.push_front(tmp);
			} 
			return true;
		} 
		bool pop(){// 出栈 
			elem.pop_front();
			min_record.pop_front();
			return true;
		} 
		T top(){return elem.front()->value;} // 访问栈元素 
		int size(){return elem.size();} // 栈大小 
		T min() { // 返回最小元素 
			return min_record.front()->value;
		}
	private:
		List<T> min_record;
		List<T> elem; // 存储元素		
};
