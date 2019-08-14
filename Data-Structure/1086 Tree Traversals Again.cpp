//
// Created by Administrator on 2019/8/12.
//

/**
Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
*/

/**
Sample Output:
3 4 2 6 5 1
 */


// 2019.8.14 17:10 reading
// 2019.8.14 17:15 read

#include <iostream>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;
#define MAX 40

int in[MAX], pre[MAX], n, x;

struct Node {
    int data;
    Node *left;
    Node *right;
};

stack<int> s;

Node *create(int preL, int preR, int inL, int inR) {
    if (preL > preR)
        return NULL;
    Node *root = new Node;
    root->data = pre[preL];

    int k;
    for (k = inL; k <= inR; k++) {
        if (in[k] == pre[preL])
            break;
    }

    int numLeft = k - inL;

    root->left = create(preL + 1, preL + numLeft, inL, k - 1);
    root->right = create(preL + numLeft + 1, preR, k + 1, inR);


    return root;
}

int t = 0;
void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
        if (t != n - 1) {
            printf(" ");
        }
        t++;
    }
}

int main() {
    scanf("%d", &n);
    for (int index = 0, p = 0, i = 0; index < 2 * n; index++) {
        char op[5];
        scanf("%s", op);
        if (strcmp(op, "Push") == 0) {
            scanf("%d", &x);
            s.push(x);
            pre[p++] = x;
        } else {
            in[i++] = s.top();
            s.pop();
        }
    }


    Node *root = create(0, n - 1, 0, n - 1);
    postorder(root);
}

//PAT AC 17:34