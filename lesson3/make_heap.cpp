#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// ѹ���
void push_heap(int *s, int *e) {
	int len = e-s;
	int cur = len-1;
	while(cur > 0) {
		// �õ����׵��±�
		int pIndex = (cur-1) / 2;
		// ��ǰԪ���븸�ױȽϣ�С�ھ����� 
		if (s[cur] > s[pIndex]) {
			int tmp = s[cur];
			s[cur] = s[pIndex];
			s[pIndex] = tmp;
		}
		cur = pIndex;
	}
} 

// ������ 
void make_heap(int *s, int *e) {
	// [s,e) ��ɶ�
	int len = e - s;
	for (int i=1;i< len;i++) {
		push_heap(s,s+i);
	}
}

// ������
void pop_heap(int *s, int *e) {
	int len = e - s;
	// ������β��Ԫ��
	int tmp = s[0];
	s[0] = s[len-1];
	s[len-1] = tmp;
	// �Ѷ�Ԫ������
	int cur = 0;
	while(cur < (len-1)/2) {
		int leftIndex = cur * 2 + 1;
		int rightIndex = cur * 2 + 2;
		// �ҵ������нϴ��
		int maxIndex = (s[leftIndex] > s[rightIndex]) ? leftIndex : rightIndex;
		// �Ƚϸ��ڵ����ӽڵ��нϴ���
		if (s[cur] < s[maxIndex]) {
			int tmp = s[cur];
			s[cur] = s[maxIndex];
			s[maxIndex] = tmp;
		}
		cur = maxIndex;
	}
}




//int main(int argc, char** argv) {
//	int a[10] = {10,20,30,5,15};
//	make_heap(a,a+5);
//	for (int i = 0;i<10;i++) {
//		cout << a[i] << " " ;
//	}
//	cout << endl;
//	pop_heap(a,a+5);
//	for (int i = 0;i<10;i++) {
//		cout << a[i] << " " ;
//	}
//	cout << endl;
//	pop_heap(a,a+4);
//	for (int i = 0;i<10;i++) {
//		cout << a[i] << " " ;
//	}
//	cout << endl;
//	a[3]=90;
//	push_heap(a,a+4);
//	for (int i = 0;i<10;i++) {
//		cout << a[i] << " " ;
//	}
//	cout << endl;
//	return 0;
//}
