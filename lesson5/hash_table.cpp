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
    bool insert(string newelem);          // �����Ԫ�غ�KEY����
    bool remove(string elem);             // ɾ��ĳ��Ԫ��
    bool search(string elem);            // ����ĳ��Ԫ��
private:
    int myhash(string key);               // ��ɢ��ֵ
    list<string> data[HASHMAX];           // ɢ�б�Ĵ���
};

int hash_table::myhash(string key) {
	int hash = 0;
	for(int i=0;i<key.length();i++) {
		hash = hash * 131 + key[i];
	}
	return hash % HASHMAX;
}

bool hash_table::insert(string newelem) {
	int index = myhash(newelem);
	typename list<string>::iterator p;
	for(p=data[index].begin();p!=data[index].end();p++)
		if (*p == newelem) return true;
	data[index].push_front(newelem);
	return 0;	
}

bool hash_table::remove(string elem) {
	int index = myhash(elem);
	typename list<string>::iterator p;
	for(p=data[index].begin();p!=data[index].end();p++)
		if (*p == elem) {
			data[index].erase(p);
			break;
		}
	return true;
}

bool hash_table::search(string elem) {
	int index = myhash(elem);
	typename list<string>::iterator p;
	for(p=data[index].begin();p!=data[index].end();p++)
		if (*p == elem) return true;
	return false;
}


int main(int argc, char** argv) {
	hash_table h;
	h.insert("A");
	h.insert("B");
	cout << h.search("A") << endl;
	h.remove("A");
	cout << h.search("A") << endl;
	return 0;
}
