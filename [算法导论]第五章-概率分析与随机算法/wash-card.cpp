// 洗牌算法
#include <cstdlib>
#include <iostream>
#include <ctime>

void wash_card(int list[], int len) {
    for (int i = 0; i < len; i++) {
        int j = std::rand() % (len - i) + i;
        std::swap(list[i], list[j]);
    }
}

int main() {
    std::srand(std::time(NULL));
    int list[] = {4, 1, 3, 5, 6, 7, 2, 9};
    wash_card(list, 8);
    return 0;
}