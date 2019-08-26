//
// Created by Administrator on 2019/8/26.
//

//2019.8.26 15:20 begin

/**
Sample Input:
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
Sample Output:
58 25 82 11 38 67 45 73 42
**/

#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 110;

struct Node {
    int data;
    int left;
    int right;
} node[maxn];

int in[maxn], index = 0;

void inorder(int root) {
    if (root == -1)
        return;
    inorder(node[root].left);
    node[root].data = in[index++];
    inorder(node[root].right);
}

void BFS(int root) {
    int first = 0;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int front = q.front(), left = node[front].left, right = node[front].right;
        if (first++ != 0)
            printf(" ");
        printf("%d", node[front].data);
        q.pop();
        if (left != -1)
            q.push(left);
        if (right != -1)
            q.push(right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &node[i].left, &node[i].right);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    sort(in, in + n);
    inorder(0);
    BFS(0);
}

//15:50 AC