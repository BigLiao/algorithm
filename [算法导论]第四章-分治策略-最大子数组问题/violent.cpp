#include <iostream>
using namespace std;

int P[15] = {23,11, 13, 5, 15, 32, 25, 27, 19, 20, 16, 12, 22, 24, 18};

// 变换成差分
void transformArray(int list[], int len) {
    for (int i = 0; i < len - 1; i++) {
        list[i] = list[i + 1] - list[i];
    }
    list[len-1] = 0;
}

void findMaxChange(int list[], int len) {
    int max = -9999;
    int maxLeft = 0, maxRight = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            int change = list[j] - list[i];
            if (max < change) {
                max = change;
                maxLeft = i;
                maxRight = j;
            }
        }
    }
    cout << "Largest change is " << max << ": from " << maxLeft << " to " << maxRight << endl;
}

void findMaxSubArrayViolent(int list[], int len) {
    transformArray(P, 15);
    // 求出部分和
    int subSumArray[14];
    subSumArray[0] = list[0];
    for (int i = 1; i < len; i++) {
        subSumArray[i] = subSumArray[i - 1] + list[i];
    }
    // 求出最大子数组
    int max = list[0];
    int maxLeft = 0, maxRight = 1;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int sum = subSumArray[j] - subSumArray[i];
            if (sum > max) {
                max = sum;
                maxLeft = i;
                maxRight = j;
            }
        }
    }
    cout << "Largest change is " << max << ": from " << maxLeft << " to " << maxRight << endl;
}

int main() {
    // 
    findMaxSubArrayViolent(P, 13);
    
    return 0;
}