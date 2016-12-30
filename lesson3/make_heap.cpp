#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// 压入堆
void push_heap(int *s, int *e) {
	int len = e-s;
	int cur = len-1;
	while(cur > 0) {
		// 得到父亲的下标
		int pIndex = (cur-1) / 2;
		// 当前元素与父亲比较，小于就上行 
		if (s[cur] > s[pIndex]) {
			int tmp = s[cur];
			s[cur] = s[pIndex];
			s[pIndex] = tmp;
		}
		cur = pIndex;
	}
} 

// 创建堆 
void make_heap(int *s, int *e) {
	// [s,e) 组成堆
	int len = e - s;
	for (int i=1;i< len;i++) {
		push_heap(s,s+i);
	}
}

// 弹出堆
void pop_heap(int *s, int *e) {
	int len = e - s;
	// 交换首尾部元素
	int tmp = s[0];
	s[0] = s[len-1];
	s[len-1] = tmp;
	// 堆顶元素下行
	int cur = 0;
	while(cur < (len-1)/2) {
		int leftIndex = cur * 2 + 1;
		int rightIndex = cur * 2 + 2;
		// 找到子树中较大的
		int maxIndex = (s[leftIndex] > s[rightIndex]) ? leftIndex : rightIndex;
		// 比较父节点与子节点中较大者
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
