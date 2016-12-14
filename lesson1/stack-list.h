using namespace std;

template<class T>
class StackList {
	public:
		StackList(){}
		~StackList(){}
		bool push (T newelem){elem.push_front(newelem);} // ��ջ 
		bool pop(){elem.pop_front();} // ��ջ 
		T top(){return elem.front()->value;} // ����ջԪ�� 
		int size(){return elem.size();} // ջ��С 
	private:
		List<T> elem; // �洢Ԫ��		
};

