//
// Created by Administrator on 2019/8/15.
//

/**
Sample Input:
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
*/

/**
Sample Output:
1.85 2
 */


// 2019.8.17 12:42 reading
// 2019.8.17 12:42 read

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> children[100010];
double p, r, ans = 0;
int n, maxDepth = 0, num = 0, root;

void DFS(int index, int depth) {
    //到达叶节点
    if (children[index].empty()) {
        if(depth > maxDepth){
            maxDepth = depth;
            num = 1;
        }else if(depth == maxDepth){
            num++;
        }
    }
    for (int i = 0; i < children[index].size(); i++)
        DFS(children[index][i], depth + 1);
}

int main() {

    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for (int i = 0, k; i < n; i++) {
        scanf("%d", &k);
        if (k != -1)
            children[k].push_back(i);

        else
            root = i;
    }

    DFS(root, 0);

    printf("%.2f %d\n", p * pow(1+r, maxDepth), num);
}

//12:50 AC