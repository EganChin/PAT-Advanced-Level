//
// Created by Administrator on 2019/8/12.
//

/**
Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
*/

/**
Sample Output:
4 1 6 3 5 7 2
 */


// 2019.8.14 16:10 reading
// 2019.8.14 16:25 read

#include <iostream>
#include <queue>

using namespace std;
#define MAX 40

int in[MAX], post[MAX], n;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *create(int postL, int postR, int inL, int inR) {
    if (postL > postR)
        return NULL;
    Node *root = new Node;
    root->data = post[postR];

    int k;
    for (k = inL; k <= inR; k++) {
        if (in[k] == post[postR])
            break;
    }

    int numLeft = k - inL;

    root->left = create(postL, postL + numLeft - 1, inL, k - 1);
    root->right = create(postL + numLeft, postR - 1, k + 1, inR);


    return root;
}

void BFS(Node *root) {
    queue<Node *> q;
    q.push(root);
    for (int i = 0; !q.empty(); i++) {
        Node *node = q.front();
        q.pop();
        printf("%d", node->data);
        if (i != n - 1)
            printf(" ");
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);

    Node *root = create(0, n - 1, 0, n - 1);
    BFS(root);
}

//17:04 AC