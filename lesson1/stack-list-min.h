using namespace std;

template<class T>
class StackList {
	public:
		StackList(){}
		~StackList(){}
		bool push (T newelem){// ��ջ 
			elem.push_front(newelem);
			if (min_record.size() == 0) min_record.push_front(newelem);
			else {
				T tmp = min_record.front()->value;
				if (newelem < tmp) tmp = newelem;
				min_record.push_front(tmp);
			} 
			return true;
		} 
		bool pop(){// ��ջ 
			elem.pop_front();
			min_record.pop_front();
			return true;
		} 
		T top(){return elem.front()->value;} // ����ջԪ�� 
		int size(){return elem.size();} // ջ��С 
		T min() { // ������СԪ�� 
			return min_record.front()->value;
		}
	private:
		List<T> min_record;
		List<T> elem; // �洢Ԫ��		
};
