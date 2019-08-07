#include <iostream>
using namespace std;

int P[13] = {23, 13, 5, 32, 25, 27, 19, 20, 16, 12, 22, 24, 18};
int main() {

    int D[12];
    for (int i = 0; i < 13; i++) {
        cout << P[i + 1] - P[i] << ", ";
    }

    return 0;
}