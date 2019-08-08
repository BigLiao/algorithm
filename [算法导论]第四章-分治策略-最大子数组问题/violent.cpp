#include <iostream>
using namespace std;

int P[13] = {23, 13, 15, 32, 25, 27, 19, 20, 16, 12, 22, 24, 18};

void findMaxChange(int list[], int len) {
    int max = -9999; // 可能出现负数，所以取负无穷作为初始化
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
    cout << "Max change is " << max << ": from " << maxLeft << " to " << maxRight << endl;
}

int main() {
    findMaxChange(P, 13);
    return 0;
}