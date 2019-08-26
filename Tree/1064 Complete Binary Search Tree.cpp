//
// Created by Administrator on 2019/8/26.
//

//2019.8.26 14:46

/**
Sample Input:
10
1 2 3 4 5 6 7 8 9 0
Sample Output:
6 3 8 1 5 7 9 0 2 4
**/

#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;


int key[1010], CBT[1010], n, index=0;

void create(int root){
    if(root > n) return;
    create(root*2);
    CBT[root] = key[index++];
    create(root*2+1);
}


int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &key[i]);
    }

    sort(key, key+n);

    create(1);
    printf("%d", CBT[1]);
    for(int i=2; i<=n;i++){
        printf(" %d", CBT[i]);
    }
}

//15:10 AC