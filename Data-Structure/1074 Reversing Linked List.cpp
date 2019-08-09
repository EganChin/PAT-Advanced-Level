//
// Created by Administrator on 2019/8/5.
//

/**
 * Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.

Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10
​5
​​ ) which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next
where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:
For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

00100 6 2
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1


00000 6 3
00000 1 11111
11111 2 22222
22222 3 -1
33333 4 44444
44444 5 55555
55555 6 -1
 * */
//2019.8.8 17:00 reading
//2019.8.8 17:06 read

#include <iostream>

using namespace std;

struct Node {
    int data;
    int next;
} node[100010];

int n, k;

int reverse(int head, int valid) {


    int reverseBegin = 0;

    //划分为n/k块，每k个反转
    for (int i = 0,temp; i < (valid / k); i++) {
        //本块开始地址，下一个地址，下下个地址
        int blockBegin, next, afterNext;
        next = node[head].next;
        blockBegin = next;
        afterNext = node[next].next;

        //反转本块
        for (int j = 1; j < k; j++) {
            temp = node[afterNext].next;
            node[afterNext].next = next;
            next = afterNext;
            afterNext = temp;
        }
        node[node[head].next].next = afterNext;
        node[head].next = next;
        head = blockBegin;

        if (i == 0) {
            reverseBegin = next;
        }
    }

    return reverseBegin;
}

int main() {
    int head, address, last, next;
    scanf("%d%d%d", &head, &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%05d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
    }
    //计算有效节点数
    int h = head, valid = 0;
    while (h != -1) {
        h = node[h].next;
        valid++;
    }

    //哨兵
    node[100001].next = head;
    head = reverse(100001, valid);

    while (head != -1) {
        printf("%05d %d ", head, node[head].data);
        node[head].next != -1 ? printf("%05d", node[head].next) : printf("-1");
        printf("\n");
        head = node[head].next;
    }
}

//+1 12:28 PAT AC