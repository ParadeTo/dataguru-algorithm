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
    int insert(string newelem);          // �����Ԫ�غ�KEY����
    int remove(string elem);             // ɾ��ĳ��Ԫ��
    bool search(string elem);            // ����ĳ��Ԫ��
        int myhash(string key);               // ��ɢ��ֵ
private:

    list<string> data[HASHMAX];           // ɢ�б�Ĵ���
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
