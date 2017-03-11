//
//  list_sort.cpp
//  lesson6
//
//  Created by youxingzhi on 17/1/21.
//  Copyright © 2017年 youxingzhi. All rights reserved.
//


#include <iostream>
using namespace std;

struct listnode {
    int value;
    listnode * next;
};


listnode *initData(int n) {
    listnode * head = new listnode();
    listnode * p=head;
    for (int i=n;i>0;i--) {
        listnode *item = new listnode();
        item->value = i;
        p->next = item;
        p = item;
    }
    p->next = NULL;
    return head;
}

void display(listnode *head) {
    listnode *p = head->next;
    while(p!=NULL) {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

listnode * merge(listnode *leftStart, int leftN, listnode *rightStart, int rightN) {
    listnode *l = leftStart;
    int iL = 0;
    listnode *r = rightStart;
    int iR = 0;
    
    listnode *_head = new listnode();
    listnode *c = _head;
    
    while(iL < leftN || iR < rightN) {
        // 如果左边遍历完了
        if(iL == leftN) {
            c->next = r;
            c = r;
            r = r->next;
            iR ++ ;
        }
        // 如果右边遍历完了
        else if(iR == rightN) {
            c->next = l;
            c = l;
            l = l->next;
            iL++;
        }
        // 都没有遍历完
        else {
            if(l->value <= r->value) {
                c->next = l;
                c = c->next;
                l = l->next;
                iL++;
            } else {
                c->next = r;
                c = c->next;
                r = r->next;
                iR ++ ;
            }
        }
    }
    return _head->next;
}

listnode* divide(listnode *start,int n) {
    listnode *left;
    listnode *right;
    int leftN = n/2;
    if (n > 1) {
        int i = 1;
        listnode *p2 = start;
        listnode *p1;
        while(i<=leftN){
            p1 = p2;
            p2 = p2->next;
            i++;
        }
        p1->next = NULL;
        left = start;
        right = p2;
        left = divide(left, leftN);
        right = divide(right, n-leftN);
        listnode *pMerge = merge(left,leftN,right,n-leftN);
        return pMerge;
    } else {
        return start;
    }

}

void dcSort(listnode *head,int n) {
    head->next = divide(head->next,n);
}



int main(int argc, const char * argv[]) {
    listnode *head = initData(6);
    display(head);
    dcSort(head,6);
    display(head);
    return 0;
}
