//
// Created by Administrator on 2019/8/26.
//

//2019.8.26 14:00 begin

/**
Sample Input 1:
7
8 6 5 7 10 8 11
Sample Output 1:
YES
5 7 6 8 11 10 8
Sample Input 2:
7
8 10 11 8 6 7 5
Sample Output 2:
YES
11 8 10 7 5 6 8
Sample Input 3:
7
8 6 8 5 10 9 11
Sample Output 3:
NO
**/

#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

string inputSeq = "", preSeq = "", postSeq = "";
bool invert = false;

void preOrder(Node *root) {
    if (root != NULL) {
        preSeq += " " + to_string(root->data);
        if (invert) {
            preOrder(root->right);
            preOrder(root->left);
        } else {
            preOrder(root->left);
            preOrder(root->right);
        }
    }
}

void postOrder(Node *root) {
    if (root != NULL) {
        if (invert) {
            postOrder(root->right);
            postOrder(root->left);
        } else {
            postOrder(root->left);
            postOrder(root->right);
        }

        postSeq += " " + to_string(root->data);
    }
}

void insert(Node *&root, int x) {
    if (root == NULL) {
        root = new Node(x);
        return;
    }
    if (x >= root->data) {
        insert(root->right, x);
    } else {
        insert(root->left, x);
    }
}

int main(){
    int n,x;
    scanf("%d",&n);
    Node *root = NULL;
    for(int i=0;i<n;i++){
        scanf("%d", &x);
        inputSeq += " " + to_string(x);
        insert(root, x);
    }


    preOrder(root);
    if(preSeq != inputSeq){
        invert = true;
        preSeq = "";
        preOrder(root);
        if(preSeq != inputSeq){
            cout << "NO" << endl;
//            cout << preSeq << endl;
            return 0;
        }
    }

    postOrder(root);

    cout << "YES" << endl;
    cout << postSeq.substr(1,postSeq.size()-1) << endl;
}

//14:33 AC