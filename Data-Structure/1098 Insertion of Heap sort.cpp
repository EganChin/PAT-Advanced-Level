//
// Created by Administrator on 2019/8/26.
//

/**
Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:
10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
Sample Output 2:
Heap Sort
5 4 3 1 0 2 6 7 8 9


82
9 75 65 42 22 3 69 5 41 11 77 25 10 45 17 2 43 15 47 58 56 82 31 44 73 24 63 4 29 37 72 81 64 8 26 62 68 21 18 14 19 1 71 67 35 39 61 48 46 59 52 13 34 20 79 30 12 50 51 7 23 60 57 49 74 27 32 6 33 40 36 54 55 70 80 38 53 66 78 76 16 28
59 58 57 55 56 52 51 49 54 28 39 48 34 50 38 42 43 41 53 21 18 35 31 46 27 26 20 30 45 37 17 11 32 33 40 36 6 2 47 16 5 1 15 22 9 19 8 44 23 25 14 13 24 3 10 4 12 7 29 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82


 */

//2019.8.27 10:04 begin

#include <iostream>

using namespace std;

const int maxn = 110;
int n, target[maxn], insertion[maxn], heap[maxn];

void print(int a[]) {
    printf("%d", a[1]);
    for (int i = 2; i <= n; i++)
        printf(" %d", a[i]);
    printf("\n");
}

bool isSame(int a[]) {
    for (int i = 1; i <= n; i++)
        if (a[i] != target[i])
            return false;
    return true;
}

bool isInsertSort() {
    bool is = false;
    for (int i = 2; i <= n; i++) {
        int j = i, temp = insertion[i];
        if (i != 2 && isSame(insertion))
            is = true;
        while (temp < insertion[j - 1] && j > 0) {
            insertion[j] = insertion[j - 1];
            j--;
        }
        insertion[j] = temp;
        if (is)
            return is;
    }
    return is;
}

void downAdjust(int low, int height) {
    int i = low, j = i * 2;
    while (j <= height) {
        if (j + 1 <= height && heap[j + 1] > heap[j]) {
            j = j + 1;
        }
        if (heap[j] > heap[i]) {
            swap(heap[j], heap[i]);
            i = j;
            j = i * 2;
        } else {
            break;
        }
    }
}

void createHeap() {
    for (int i = n / 2; i >= 1; i--)
        downAdjust(i, n);
}

bool isHeapSort() {

    createHeap();

    bool is = false;
    for (int i = n; i > 1; i--) {
        if (i != n && isSame(heap))
            is = true;
        swap(heap[1], heap[i]);
        downAdjust(1, i - 1);
        if (is)
            return is;
    }
    return is;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &insertion[i]);
        heap[i] = insertion[i];
    }

    for (int i = 1; i <= n; i++)
        scanf("%d", &target[i]);

    if (isInsertSort()) {
        printf("Insertion Sort\n");
        print(insertion);
    } else {
        isHeapSort();
        printf("Heap Sort\n");
        print(heap);
    }
}

//11:48 AC