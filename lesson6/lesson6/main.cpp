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
//#define CONST_K 7
//#define MAX 100
//#define TEST_TIME 1000
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
//    } else {
//        // 插入排序
//    }
//}
//
//int* random_arr(int n) {
//    int *a = new int[n];
//    for (int i=0;i<n;i++) {
//        a[i] = rand()%(MAX+1);
//    }
//    return a;
//}
//
//void display(int *a,int n) {
//    for (int i=0; i<n; i++) {
//        cout << a[i] << ' ';
//    }
//    cout << endl;
//}
//
//// 测试插入排序的平均速度 n-数组长度，m－测试次数
//int testInsertSort(int n) {
//    long quickT = 0;
//    long insertT = 0;
//    
//    int *arr = random_arr(n);
//    
//    // 测试m次
//    // 插入排序时间
//    clock_t start1 = clock();
//    for(int i=0;i<TEST_TIME;i++) {
//        int *arr1 = new int[n];
//        memcpy(arr1, arr, sizeof(int)*n);
//        insert_sort(arr1,0, n-1);
//        delete[] arr1;
//    }
//    clock_t end1 = clock();
//    insertT = end1 - start1;
//    
//    // 快速排序时间
//    clock_t start2 = clock();
//    for(int i=0;i<TEST_TIME;i++) {
//        int *arr2 = new int[n];
//        memcpy(arr2, arr, sizeof(int)*n);
//        quick_sort(arr2,0, n-1);
//        delete [] arr2;
//    }
//    clock_t end2 = clock();
//    quickT = end2 - start2;
//    
//    cout << "长度为" << n << "测试结果：" << endl;
//    cout << "快速排序：" << quickT << "ms  插入排序："  << insertT << "ms" << endl;
//    delete [] arr;
//    return 0;
//}
//
////int main(int argc, const char * argv[]) {
////    srand(time(0));
////    
////    for(int i=2;i<30;i++) {
////        testInsertSort(i);
////    }
//////     int *arr = random_arr(2);
//////            insert_sort(arr,0, 2);
//////    display(arr, 2);
//////         int *arr2 = random_arr(2);
//////    quick_sort(arr2, 0,2);
//////        display(arr2, 2);
//////    
//////    for(int i=0;i<TEST_TIME;i++) {
//////        int *arr2 = random_arr(3);
//////        //        memcpy(arr2, arr, sizeof(int)*n);
//////        
//////        quick_sort(arr2,0, 2);
//////        delete arr2;
//////    }
//////    testInsertSort(3);
////
////    cout << "结束" << endl;
////    return 0;
////}
