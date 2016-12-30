#include <iostream>
#include <list>
using namespace std;

// ����ת������ 
list<int> BinaryVector(int n) {
	int temp;  
	temp=n;  
	list<int> L;  
	while(temp!=0)  
	{  
		L.push_front(temp%2);  
		temp=temp >> 1;  
	}  
	return L;
}

template<class T>
class treenode {
	public:
		treenode() ;
		treenode(T newelem){
			value = newelem;
			parent = leftchild = rightchild = NULL;
		}
		T value;
		treenode *parent, *leftchild, *rightchild; 
};

template<class T>
class heap {
	public:
		heap() {
			root = NULL;
			size = 0;
		}
		~heap(){
		}
		bool push(T newelem);
		T pop();
		void recursion_inorder_traversal();
		void recursion_preorder_traversal();
	private:
		int size;
		treenode<T> *root;
		void _recursion_inorder_traversal(treenode<T> *p);
		void _recursion_preorder_traversal(treenode<T> *p);
};


// �������
template <class T>  
void heap<T>::_recursion_inorder_traversal(treenode<T> *p) {
	if (p==NULL) return;
	_recursion_inorder_traversal(p->leftchild);
	cout << p->value << ' ';
	_recursion_inorder_traversal(p->rightchild);
	return ;
}

template <class T>  
void heap<T>::recursion_inorder_traversal() {
	_recursion_inorder_traversal(root);
}

// ǰ�����
template <class T>  
void heap<T>::_recursion_preorder_traversal(treenode<T> *p) {
	if (p==NULL) return;
	cout << p->value << " ";
	_recursion_preorder_traversal(p->leftchild);
	_recursion_preorder_traversal(p->rightchild);
	return ;
} 

template <class T>  
void heap<T>::recursion_preorder_traversal() {
	_recursion_preorder_traversal(root);
}

//  ���� 
template <class T>  
bool heap<T>::push(T newelem) {
	// ����+1 
	size += 1; 
	// ����һ���ڵ� 
	treenode<T> *p = new treenode<T>(newelem);
	
	// ��һ���ڵ�Ϊ���ڵ� 
	if (size == 1) {
		root = p;
		return true;
	}
	
	// ���뵽��β 
	list<int> L = BinaryVector(size);
	list<int>::iterator iter=L.begin();
	treenode<T> *rec = root;
	for (iter++;iter!=L.end();iter++) {
		// ������ 
		if (*iter == 0) {
			if (rec->leftchild == NULL) {
				rec->leftchild = p;
				p->parent = rec;
				break;
			}
			rec = rec->leftchild;
		}
		// ������
		if (*iter == 1) {
			if (rec->rightchild == NULL) {
				rec->rightchild = p;
				p->parent = rec;
				break;
			}
			rec = rec->rightchild;
		}
	}
	
	// ����
	while(p->parent != NULL && p->value > p->parent->value) {
		T tmp = p->value;
		p->value = p->parent->value;
		p->parent->value = tmp;
		p = p->parent;
	} 
}

// ����
template <class T>  
T heap<T>::pop() {
	if(size == 0) {
		T nil;
		return nil;
	}
	
	
	T res = root->value;
	if (size == 1) {
		delete root;
		return res;
	}
	
	// ������βԪ�ز�ɾ��β�� 
	list<int> L = BinaryVector(size);
	list<int>::iterator iter=L.begin();
	treenode<T> *rec = root;
	for (iter++;iter!=L.end();iter++) {
		// ������ 
		if (*iter == 0) {
			rec = rec->leftchild;
			// ������Ҷ�ӽڵ� 
			if(rec->leftchild == NULL && rec->rightchild == NULL)
				rec->parent->leftchild = NULL;
		}
		// ������
		if (*iter == 1) {
			rec = rec->rightchild;
			// ������Ҷ�ӽڵ� 
			if(rec->leftchild == NULL && rec->rightchild == NULL)
				rec->parent->rightchild = NULL;
		}
	}
	T tmp = rec->value;
	rec->value = root->value;
	root->value = tmp; 
	delete rec;
	
	size -= 1;
	
	// ����Ԫ������
	L = BinaryVector(size);
	treenode<T> *p = root;
	for (iter=L.begin();iter!=L.end();iter++) {
		if (p->leftchild == NULL && p->rightchild == NULL) break;
		// �ҵ������нϴ��
		treenode<T> *maxChild;
		if (p->leftchild == NULL) {
			maxChild = p->rightchild;
		} else if (p->rightchild == NULL) {
			maxChild = p->leftchild;
		} else {
			maxChild = (p->leftchild->value > p->rightchild->value) ? p->leftchild : p->rightchild;
		}
		// �Ƚϸ��ڵ����ӽڵ��нϴ��߲����� 
		if (p->value < maxChild->value) {
			T tmp = p->value;
			p->value = maxChild->value;
			maxChild->value = tmp;
		} 
		p = maxChild;
	}
	return res;
}


int main(int argc, char** argv) {

	heap<int> *h = new heap<int>();
	h->push(2);
	h->push(1);
	h->push(3);
	h->push(4);
	cout << "�������" << endl;
	h->recursion_inorder_traversal();
	cout << endl;
	cout << "ǰ�����" << endl;
	h->recursion_preorder_traversal();
	cout << endl;
	int a = h->pop();
	cout << endl;
	cout << a << endl;
	a = h->pop();
	cout << a << endl;
	a = h->pop();
	cout << a << endl;
	a = h->pop();
	cout << a << endl;

	return 0;
}
