#include <iostream>
#include <list>


using namespace std;

template <class T>
list<T> combine(list<T>  a, list<T>  b){
	list<T> c;
	typename std::list<T>::iterator iter_a = a.begin();
	typename std::list<T>::iterator iter_b = b.begin();

	while (iter_a != a.end() || iter_b != b.end()) {
		if(iter_a == a.end()) { // a已经遍历完 
			c.push_back(*iter_b);
			++iter_b;
			continue;
		}
		if(iter_b == b.end()) { // b已经遍历完 
			c.push_back(*iter_a);
			++iter_a;
			continue;
		}
		// 都没有遍历完 		
		if (*iter_a < *iter_b) {
			c.push_back(*iter_a);
			++iter_a;
		} else if (*iter_a > *iter_b) {
			c.push_back(*iter_b);
			++iter_b;
		} else {
			c.push_back(*iter_a);
			++iter_a;
			++iter_b;
		}
	}	
	return c;
}

int main(int argc, char** argv) {

	list<int> c;
	list<int>::iterator iter;
	
	list<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	for(iter = a.begin();iter != a.end();++iter) cout << *iter << "->";
	
	cout << endl;
	
	list<int> b;
	b.push_back(2);
	b.push_back(3);
	b.push_back(5);
	for(iter = b.begin();iter != b.end();++iter) cout << *iter << "->";
	
	cout << endl;
	
	c = combine(a, b);
	
	for(iter = c.begin();iter != c.end();++iter) cout << *iter << "->";

}
