//
// Created by Administrator on 2019/8/26.
//

//2019.8.26 16:20:00 begin

/**
 Sample Input 1:
5
88 70 61 96 120
Sample Output 1:
70
Sample Input 2:
7
88 70 61 96 120 90 65
Sample Output 2:
88
**/

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data, height;
    Node *left, *right;

    Node(int x) {
        data = x;
        height = 1;
        left = right = NULL;
    };
};

int getHeight(Node *root) {
    if (root == NULL)
        return 0;
    return root->height;
}

int getBalaceFactor(Node *root) {
    return getHeight(root->left) - getHeight(root->right);
}

void updateHeight(Node *root){
    root->height = max(getHeight(root->left),getHeight(root->right))+1;
}

void L(Node* &root){
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(Node* &root){
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(Node *&root, int x){
    if(root == NULL){
        root = new Node(x);
        return;
    }
    if(x<root->data){
        insert(root->left, x);
        updateHeight(root);
        if(getBalaceFactor(root) == 2){
            if(getBalaceFactor(root->left) == 1)
                R(root);
            else if(getBalaceFactor(root->left) == -1){
                L(root->left);
                R(root);
            }
        }
    } else{
        insert(root->right, x);
        updateHeight(root);
        if(getBalaceFactor(root) == -2){
            if(getBalaceFactor(root->right) == -1)
                L(root);
            else if(getBalaceFactor(root->right) == 1){
                R(root->right);
                L(root);
            }
        }
    }
}

int main(){
    int n,x;
    scanf("%d", &n);
    Node *root = NULL;
    for(int i=0; i<n; i++){
        scanf("%d", &x);
        insert(root, x);
    }

    printf("%d", root->data);
}

//16:35 AC
