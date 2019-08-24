//
// Created by Administrator on 2019/8/15.
//

//2019.8.24 12:39 reading
//2019.8.24 12:42 reading

/**
Sample Input:
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
Sample Output:
10 5 2 7
10 4 10
10 3 3 6 2
10 3 3 6 2

 Sample Input:
4 1 2
1 1 1 1
00 3 01 02 03
Sample Output:
1 1
1 1
1 1
 */

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 110;

int n, m, s, id, k, x;

struct Node{
    int weight;
    vector<int> children;
}node[maxn];

int compare(int n1, int n2){
    return node[n1].weight > node[n2].weight;
}

void DFS(int parent, int count, string p) {
    if (node[parent].children.empty() && count == s) {
        cout << p << endl;
    }
    for (auto & i : node[parent].children) {
        int w = node[i].weight;
        DFS(i,  count + w, p + " " + to_string(w));
    }
}

int main(){
    scanf("%d%d%d", &n,&m,&s);
    for(int i=0; i<n; i++){

        scanf("%d", &node[i].weight);
    }
    for(int i=0; i<m; i++){
        scanf("%d%d", &id,&k);
        for(int j=0; j<k; j++){
            scanf("%d", &x);
            node[id].children.push_back(x);
        }
        sort(node[id].children.begin(), node[id].children.end(), compare);
    }

    DFS(0, node[0].weight, to_string(node[0].weight));
}

//14:25 AC