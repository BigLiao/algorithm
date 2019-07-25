#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void insertion_sort(int list[], int length)
{
  for (int i = 0; i < length; i++) {
    cout << list[i] << ' ';
  }
  
}

int main() {

  int a[] = {13, 41, 11, 2, 42, 12, 43, 8};
  insertion_sort(a, 8);
  return 0;
}
