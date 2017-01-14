#include <iostream>
#include <math.h>
#define HASHMAX 1000
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class hash_table{
public:
    hash_table(){for (int i=0;i<HASHMAX;i++) data[i]=-1;};
    ~hash_table(){};
    bool insert(int newelem);          // �����Ԫ�غ�KEY����
    bool remove(int elem);             // ɾ��ĳ��Ԫ��
    bool search(int elem);            // ����ĳ��Ԫ��
	void display(int n); //�鿴data��ǰn��Ԫ�� 
private:
	int p(int i); // ����̽�鷨̽�麯�� 
    int myhash(int key);               // ��ɢ��ֵ
    int data[HASHMAX];           // ɢ�б�Ĵ���

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
	// ��λ������,���ö���̽�鷨�ҵ��µ�λ�� 
	while (data[index] != -1) {
		index = abs((myhash(newelem) + p(i++)) % HASHMAX);
		// ��Ԫ���Ѿ�������� 
		if (data[index] == newelem) return true;
	}
	data[index] = newelem;
	return true;
}

bool hash_table::remove(int elem) {
	int index = myhash(elem);
	int i=1;
	int lastIndex=-99999; 
	// ������Ԫ�� 
	if(data[index] == -1) return true;
	// ���Ҹ�Ԫ�� 
	while (data[index] != -1) {
		index = abs((myhash(elem) + p(i++)) % HASHMAX);
		// �ҵ���Ԫ�� 
		if (data[index] == elem) {
			lastIndex = index;
		}
		// �Ѻ����Ԫ��ǰ�� 
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
	// ������Ԫ�� 
	if(data[index] == -1) return false;
	// ��λ������,���ö���̽�鷨�ҵ�λ�� 
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
