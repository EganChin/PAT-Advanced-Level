//
// Created by Administrator on 2019/8/12.
//

/**
Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
*/

/**
Sample Output:
3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1
 */


// 2019.8.14 17:40 reading
// 2019.8.14 17:44 read

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 110;
struct Node {
    int left, right;
} node[maxn];

bool notRoot[maxn] = {false};

int n, num = 0;

void print(int id) {
    printf("%d", id);
    num++;
    if (num < n) printf(" ");
    else printf("\n");
}

void inOrder(int root) {
    if (root == -1)
        return;
    inOrder(node[root].left);
    print(root);
    inOrder(node[root].right);
}

void BFS(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        print(now);
        if (node[now].left != -1) q.push(node[now].left);
        if (node[now].right != -1) q.push(node[now].right);
    }
}

void postorder(int root) {
    if (root == -1)
        return;
    postorder(node[root].left);
    postorder(node[root].right);
    swap(node[root].left, node[root].right);
}

int strToNum(char c) {
    if (c == '-') return -1;
    notRoot[c - '0'] = true;
    return c - '0';
}

int findRoot() {
    for (int i = 0; i < n; i++) {
        if (!notRoot[i])
            return i;
    }
}

int main() {
    char left, right;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%*c%c %c", &left, &right);
        node[i].left = strToNum(left);
        node[i].right = strToNum(right);
    }
    int root = findRoot();
    postorder(root);
    BFS(root);
    num = 0;
    inOrder(root);
}

//17:58 AC