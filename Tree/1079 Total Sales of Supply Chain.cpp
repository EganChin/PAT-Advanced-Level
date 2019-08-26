//
// Created by Administrator on 2019/8/15.
//

//2019.8.15 17:10 reading
//2019.8.15 17:26 read


/**
Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3

Sample Output:
42.4
**/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Node {
    double data;
    vector<int> children;
} node[100010];


double p, r, ans = 0;

void DFS(int index, int depth) {
    //到达叶节点
    if (node[index].children.empty()) {
        ans += node[index].data * pow(1 + r, depth);
        return;
    }
    for (int i = 0; i < node[index].children.size(); i++)
        DFS(node[index].children[i], depth + 1);
}

int main() {

    int n;
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for (int i = 0, k; i < n; i++) {
        scanf("%d", &k);
        if (k == 0)
            scanf("%lf", &node[i].data);
        else
            for (int j = 0; j < k; j++) {
                int id;
                scanf("%d",&id);
                node[i].children.push_back(id);
            }
    }

    DFS(0, 0);

    printf("%.1f", p*ans);
}

//17:46 AC