//
// Created by Administrator on 2019/8/26.
//

//2019.8.26 16:58

/**
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
Sample Output:
3
4 3 1
**/

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1010;
int father[maxn], network[maxn] = {0}, hobby[maxn] = {0};

int findRoot(int x) {
    int a = x;
    while (x != father[x])
        x = father[x];
    //路径压缩
    while (a != father[a]) {
        int z = father[a];
        a = father[a];
        father[z] = x;
    }
    return x;
}


void Union(int a, int b) {
    int rootA = findRoot(a);
    int rootB = findRoot(b);
    if(rootA != rootB)
        father[rootA] = rootB;
}

void init(int n){
    for(int i=1; i<=n; i++){
        father[i] = i;
        network[i] = false;
    }
}

bool cmp(int a, int b){
    return a>b;
}

int main(){
    int n,k,h;
    scanf("%d", &n);
    init(n);
    for(int i=1; i<=n; i++){
        scanf("%d:", &k);
        for(int j=0; j<k; j++){
            scanf("%d", &h);
            if(hobby[h] == 0){
                hobby[h] = i;
            }
            Union(i, findRoot(hobby[h]));
        }
    }
    for(int i=1; i<=n; i++){
        network[findRoot(i)]++;
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(network[i])
            ans++;
    }
    printf("%d\n", ans);
    sort(network+1, network+maxn+1, cmp);
    for(int i=1; i<=ans; i++){
        printf("%d", network[i]);
        if(i<ans)
            printf(" ");
    }
}

//17:27 AC