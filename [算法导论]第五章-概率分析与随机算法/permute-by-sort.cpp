// 优先级数组随机化算法
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void quick_sort(int *al, int *ar, int *pl, int *pr);

void permute_by_sort(int list[], int len) {
    int p[len];
    for (int i = 0; i < len; i++) {
        p[i] = rand() % (len*len*len) + 1;
    }
    quick_sort(list, list + len, p, p + len);
}

// [al, ar)
void quick_sort(int *al, int *ar, int *pl, int *pr) {
    int len = ar -al;
    if (len <= 1) {
        return;
    } else {
        int pt = *pl, at = *al;
        int *aleft = al, *aright = ar - 1, *pleft = pl, *pright = pr - 1;
        while(pleft < pright) {
            while(pleft < pright && *pright >= pt) {
                pright = pright - 1;
                aright = aright - 1;
            }
            if (pleft < pright) {
                *pleft = *(pright);
                *aleft = *(aright);
                pleft = pleft + 1;
                aleft = aleft + 1;
            }
            while(pleft < pright && *pleft <= pt) {
                pleft = pleft + 1;
                aleft = aleft + 1;
            }
            if (pleft < pright) {
                *(pright) = *pleft;
                *(aright) = *aleft;
                pright = pright - 1;
                aright = aright - 1;
            }
        }
        *pleft = pt;
        *aleft = at;
        quick_sort(al, aleft-1, pl, pleft-1);
        quick_sort(aleft+1, ar, pleft+1, pr);
    }
}

int main() {
    srand(time(NULL));
    int list[] = {4, 1, 3, 5, 6, 7, 2, 9};
    permute_by_sort(list, 8);
    for (int i = 0; i < 8; i++) {
        cout << list[i] << ", ";
    }
    return 0;
}