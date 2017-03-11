//
//  main.cpp
//  lesson7
//
//  Created by youxingzhi on 17/2/3.
//  Copyright © 2017年 youxingzhi. All rights reserved.
//
using namespace std;
#include <iostream>

int count(unsigned int x) {
    // 每两位翻转
    x = ((x >> 1) & 0x55555555) | ((x & 0x55555555) << 1);
    // 每四位翻转
    x = ((x >> 2) & 0x33333333) | ((x & 0x33333333) << 2);
    // 每八位翻转
    x = ((x >> 4) & 0x0f0f0f0f) | ((x & 0x0f0f0f0f) << 4);
    // 每十六位翻转
    x = ((x >> 8) & 0x0000ffff) | ((x & 0x0000ffff) << 8);
    // 最后的翻转
    x = (x >> 16) | (x << 16);
    return x;
}

int main(int argc, const char * argv[]) {
    unsigned int x = 2;
    std::cout << count(x);
    return 0;
}
