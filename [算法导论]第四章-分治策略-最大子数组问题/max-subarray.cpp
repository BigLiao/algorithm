#include <iostream>
#include <tuple>
using namespace std;

int P[13] = {23, 13, 15, 32, 25, 27, 19, 20, 16, 12, 22, 24, 18};

// 变换成差分
void transformArray(int list[], int len) {
    for (int i = 0; i < len - 1; i++) {
        list[i] = list[i + 1] - list[i];
    }
}

tuple<int, int*, int*> findMaxSubArray(int* low, int* high);
tuple<int, int*, int*> findMaxSubArrayCross(int* low, int* mid, int* high);

// 注意左闭右开
tuple<int, int*, int*> findMaxSubArray(int* low, int* high) {
    if (high - low == 1) {
        return {*low, low, low+1};
    } else if (high - low == 2) {
        if (*low > *high) {
            return {*low, low, low+1};
        } else {
            return {*(low+1), low+1, low+2};
        }
    } else {
        int* mid = low + (high - low) / 2;
        
    }
}