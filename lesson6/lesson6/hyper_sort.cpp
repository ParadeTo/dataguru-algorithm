////
////  hyper_sort.cpp
////  lesson6
////
////  Created by youxingzhi on 17/1/21.
////  Copyright © 2017年 youxingzhi. All rights reserved.
////
//
////
////  main.cpp
////  lesson6
////
////  Created by youxingzhi on 17/1/21.
////  Copyright © 2017年 youxingzhi. All rights reserved.
////
//
//#include <iostream>
//using namespace std;
//#define CONST_K 6
//
//int insert_sort(int arr[], int L, int R) {
//    for (int i=L+1; i<=R; i++) {
//        int insert_p, insert_elem=arr[i];
//        for (insert_p=i; insert_p>L&&insert_elem<arr[insert_p-1] ;insert_p--);
//        for (int j=i; j>insert_p; j--) arr[j] = arr[j-1];
//        arr[insert_p] = insert_elem;
//    }
//    return 0;
//}
//
//int quick_sort(int arr[],int L,int R){
//    if (L>=R) return 0;
//    int base = arr[L];
//    int i=L,j=R;
//    while (i<j){
//        // 从右往左找到比base小的
//        while (i<j && arr[j]>base) j--;
//        arr[i] = arr[j];
//        // 从左往右找到比base大的
//        while (i<j && arr[i]<base) i++;
//        arr[j] = arr[i];
//    }
//    // i == j
//    arr[i] = base;
//    quick_sort(arr,L,i-1);
//    quick_sort(arr,i+1,R);
//    return 0;
//}
//
//
//void hyber_sort(int *arr, int L, int R) {
//    if (R-L > CONST_K) {
//        // 快速排序
//        quick_sort(arr,  L, R);
//    } else {
//        // 插入排序
//        insert_sort(arr, L, R);
//    }
//}
//
//
//void display(int *a,int n) {
//    for (int i=0; i<n; i++) {
//        cout << a[i] << ' ';
//    }
//    cout << endl;
//}
//
//
//
//int main(int argc, const char * argv[]) {
//    int a[6] = {5,4,6,7,8,9};
//    hyber_sort(a, 0, 5);
//    display(a, 6);
//    
//    return 0;
//}
//
