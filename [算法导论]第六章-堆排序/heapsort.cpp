#include <vector>
#include <iostream>

using namespace std;

// 调整堆，调整顶部元素
// 自己想的，比较粗糙
// 0 号位置是不用的
void max_heapify(int A[], int len) {
    int i = 1;
    int top = A[i];
    while(i <= len / 2) { // len/2 是最后一个有子节点的元素
        if (i * 2 + 1 < len) {
            // 有左右孩子
            if (A[i*2] > A[i*2+1]) {
                if (top > A[i*2]) {
                    A[i] = top;
                    break;
                } else {
                    A[i] = A[i*2];
                    i = i * 2;
                }
            } else {
                if (top > A[i*2+1]) {
                    A[i] = top;
                    break;
                } else {
                    A[i] = A[i*2+1];
                    i = i * 2 + 1;
                }
            }
        } else {
            // 只有左孩子
            if (top > A[i*2]) {
                A[i] = top;
                break;
            } else {
                A[i] = A[i*2];
                i = i*2;
            }
        }
    }
    
}

// 《算法导论上的》，利用递归
void max_heapify2(int A[], int len, int i) {
    if (i > len / 2) return;
    int largest = i;
    if (i * 2 <= len && A[i * 2] > A[largest]) {
        largest = i * 2;
    }
    if (i * 2 + 1<= len && A[i * 2 + 1] > A[largest]) {
        largest = i * 2 + 1;
    }
    if (largest != i) {
        swap(A[i], A[largest]);
        max_heapify2(A, len, largest);
    };
}

// 建造堆
void build_max_heap(int A[], int len) {
    int i = len / 2;
    while (i > 0) {
        max_heapify2(A, len, i);
        i--;
    }
}

// 排序
void heap_sort(int A[], int len) {
    build_max_heap(A, len);
    for (int i = len; i > 0; i--) {
        swap(A[1], A[i]);
        max_heapify2(A, i - 1, 1);
    }
}

int main() {
    // int list[] = {999, 16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int list[] = {999, 5, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int list2[] = {999, 10, 9, 14, 2, 3, 1, 4, 8, 7, 16};
    // max_heapify2(list, 10, 1);
    // build_max_heap(list2, 10);
    heap_sort(list2, 10);
    cout << "end";
}