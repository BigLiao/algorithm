#include <iostream>
using namespace std;

int P[16] = {23,11, 13, 5, 6, 15, 32, 25, 27, 19, 20, 16, 12, 22, 24, 18};

// 变换成差分
void transformArray(int list[], int len) {
    for (int i = 0; i < len - 1; i++) {
        list[i] = list[i + 1] - list[i];
    }
    list[len-1] = 0;
}

int findMaxSubArray(int *&low, int *&high);
int findMaxSubArrayCross(int *&low, int *&mid, int *&high);

// 注意左闭右开
int findMaxSubArray(int *&low, int *&high) {
    if (high - low == 1) {
        return *low;
    } else {
        int *mid = low + (high - low) / 2;

        int *leftLow = low;
        int *leftHigh = mid;
        int leftMax = findMaxSubArray(leftLow, leftHigh);

        int *rightLow = mid;
        int *rightHigh = high;
        int rightMax = findMaxSubArray(rightLow, rightHigh);

        int *midLow = low;
        int *midHigh = high;
        int midMax = findMaxSubArrayCross(midLow, mid, midHigh);

        if (leftMax > rightMax) {
            if (leftMax > midMax) {
                low = leftLow;
                high = leftHigh;
                return leftMax;
            } else {
                low = midLow;
                high = midHigh;
                return midMax;
            }
        } else if (rightMax > midMax) {
            low = rightLow;
            high = rightHigh;
            return rightMax;
        } else {
            low = midLow;
            high = midHigh;
            return midMax;
        }

    }
}

int findMaxSubArrayCross(int *&low, int *&mid, int *&high) {
    int *maxLow = mid - 1;
    int maxLeft = -9999;
    int *maxHigh = mid;
    int maxRight = -9999;
    // find left max
    int *left = mid - 1;
    int leftSum = 0;
    while(left - low >= 0) {
        leftSum += *left;
        if (leftSum > maxLeft) {
            maxLeft = leftSum;
            maxLow = left;
        }
        left--;
    }
    // find right max
    int *right = mid + 1;
    int rightSum = 0;
    while(high - right >= 0) {
        rightSum += *(right - 1);
        if (rightSum > maxRight) {
            maxRight = rightSum;
            maxHigh = right;
        }
        right++;
    }
    low = maxLow;
    high = maxHigh;
    return maxLeft + maxRight;
}

int main() {
    transformArray(P, 16);
    int *low = P;
    int *high = P + 15;
    int max = findMaxSubArray(low, high);
    return 0;
}