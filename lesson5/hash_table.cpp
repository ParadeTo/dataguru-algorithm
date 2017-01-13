#include <iostream>
#include <list>
#include <string>
#define HASHMAX 1000
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class hash_table{
public:
    hash_table(){for (int i=0;i<HASHMAX;i++) data[i].clear();};
    ~hash_table(){};
    int insert(string newelem);          // 插入的元素和KEY分离
    int remove(string elem);             // 删除某个元素
    bool search(string elem);            // 查找某个元素
        int myhash(string key);               // 求散列值
private:

    list<string> data[HASHMAX];           // 散列表的储存
};

int hash_table::myhash(string key) {
	int hash = 0;
	for(int i=0;i<key.length();i++) {
		cout <<  key[i] + 0;
		hash = hash * 131 + key[i];
	}
	return hash % HASHMAX;
}

hash_table::insert(string newelem) {
	
}


int main(int argc, char** argv) {
	hash_table *h;
	cout << h->myhash("FFF");
	return 0;
}
