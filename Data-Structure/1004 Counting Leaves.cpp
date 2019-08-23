//
// Created by Administrator on 2019/8/15.
//

//2019.8.23 16:37 reading
//2019.8.23 16:42 reading


/**
Sample Input:
2 1
01 1 02
Sample Output:
0 1
 */

#include <vector>
#include <iostream>
using namespace std;

const int maxn = 110;

int leveCount[maxn] = {0}, maxDepth = 0;
vector<int> node[maxn];

void DFS(int parent, int depth)
{
    if(node[parent].empty()){
        if(depth > maxDepth)
            maxDepth = depth;
        leveCount[depth]++;
    }
    for(int i=0; i<node[parent].size(); i++)
        DFS(node[parent][i], depth+1);
}

int main(){
    int n, m, id, k, x;
    scanf("%d %d", &n, &m);
    for(int i=0 ;i<m; i++){
        scanf("%0d %d", &id, &k);
        for(int j=0; j<k; j++){
            scanf("%d", &x);
            node[id].push_back(x);
        }
    }

    DFS(1,1);
    printf("%d", leveCount[1]);
    for(int i=2;i<=maxDepth;i++)
        printf(" %d", leveCount[i]);
}

//16:55 AC