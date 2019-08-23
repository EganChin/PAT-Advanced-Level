//
// Created by Administrator on 2019/8/15.
//

//2019.8.23 15:05

/**
Sample Input:
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
Sample Output:
9 4
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 110;

vector<int> node[maxn];
int levelCount[maxn] = {0};

void BFS(int parent, int level){
    levelCount[level]++;
    for(int child=0; child<node[parent].size(); child++)
        BFS(node[parent][child], level+1);
}

int main(){
    int n,m,parent,child, cNum, root;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m; i++){
        scanf("%d %d", &parent, &cNum);
        for(int j=0;j<cNum;j++){
            scanf("%d",&child);
            node[parent].push_back(child);
        }
    }

    BFS(1,1);
    int maxLevel = 0, maxChild=0;
    for(int level=1;level<maxn;level++){
        if(levelCount[level]>maxChild){
            maxChild = levelCount[level];
            maxLevel = level;
        }
    }

    printf("%d %d\n", maxChild, maxLevel);
}

//15:41 AC