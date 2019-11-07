//
// Created by Administrator on 2019/8/27.
//

/*
Sample Input:
3 2 3
1 2
1 3
1 2 3
Sample Output:
1
0
0
*/

// begin at 07/11/19 17:08 

// each query need to find the number of block, the result equals (block number - 1)

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define MAX_N 1010

vector<int> G[MAX_N];

bool visit[MAX_N];

int del;

void dfs(int u){
	if(u!=del){
		visit[u] = true;
		for(int v= 0; v<G[u].size(); v++){
			if(!visit[G[u][v]])
				dfs(G[u][v]);
		}
	}
}

int main(){
	int n,m,k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	for(int query=0; query<k; query++){
		scanf("%d", &del);
		memset(visit, false, sizeof(visit));
		int block = 0;
		for(int i=1; i<=n; i++){
			if(i!=del &&  !visit[i]){
				dfs(i);
				block++;
			}
		}
		printf("%d\n", block-1);
	}
	
}

// finish at 07/11/19 18:05






