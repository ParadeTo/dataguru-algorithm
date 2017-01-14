#include <iostream>
#include <math.h>
#define HASHMAX 1000
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class hash_table{
public:
    hash_table(){for (int i=0;i<HASHMAX;i++) data[i]=-1;};
    ~hash_table(){};
    bool insert(int newelem);          // 插入的元素和KEY分离
    bool remove(int elem);             // 删除某个元素
    bool search(int elem);            // 查找某个元素
	void display(int n); //查看data中前n个元素 
private:
	int p(int i); // 二次探查法探查函数 
    int myhash(int key);               // 求散列值
    int data[HASHMAX];           // 散列表的储存

};

void hash_table::display(int n) {
	for (int i=0;i<n;i++) {
		cout << data[i] << " ";
	}
}

int hash_table::myhash(int key) {
	return key % HASHMAX;
}

int hash_table::p(int i) {
	return pow(-1,i-1) * pow((i+1)/2,2);
}


bool hash_table::insert(int newelem) {
	int index = myhash(newelem);
	int i=1;
	if (data[index] == newelem) return true;
	// 该位置满了,利用二次探查法找到新的位置 
	while (data[index] != -1) {
		index = abs((myhash(newelem) + p(i++)) % HASHMAX);
		// 该元素已经被插入过 
		if (data[index] == newelem) return true;
	}
	data[index] = newelem;
	return true;
}

bool hash_table::remove(int elem) {
	int index = myhash(elem);
	int i=1;
	int lastIndex=-99999; 
	// 不存在元素 
	if(data[index] == -1) return true;
	// 查找该元素 
	while (data[index] != -1) {
		index = abs((myhash(elem) + p(i++)) % HASHMAX);
		// 找到该元素 
		if (data[index] == elem) {
			lastIndex = index;
		}
		// 把后面的元素前移 
		if (lastIndex != -99999 && data[index] != -1) {
			data[lastIndex] = data[index];
			lastIndex = index;
		}
	}
	if (lastIndex != -99999) {
		data[lastIndex] = -1;
	}
	return true;
}

bool hash_table::search(int elem) {
	int index = myhash(elem);
	int i=1;
	// 不存在元素 
	if(data[index] == -1) return false;
	// 该位置满了,利用二次探查法找到位置 
	while (data[index] != -1) {
		index = abs((myhash(elem) + p(i++)) % HASHMAX);
		if (data[index] == elem) return true;
	}
	return false;
}


//int main(int argc, char** argv) {
//	hash_table h;
//	h.insert(1);
//	h.insert(1001);
//	h.insert(2001);
//	h.insert(3001);
//	cout << h.search(2001) << endl;
//	h.display(10);
//	h.remove(2001);
//	cout << endl;
//	h.display(10);
//	cout << endl;
//	cout << h.search(2001) << endl;
//	return 0;
//}
