//
// Created by Administrator on 2019/8/15.
//

//2019.8.23 15:55 reading
//2019.8.23 15:59 read

/**
Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0
Sample Output:
1.8362 2
 */

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
const int maxn = 100010;

int n, num, c, x;
double p, r, minPrice = 1e12;
vector<int> node[maxn];

void DFS(int index, int depth) {
    //到达叶节点
    double ans = p * pow(1 + r, depth);
    if (node[index].empty()) {
        if (ans < minPrice) {
            minPrice = ans;
            num = 1;
        } else if (ans == minPrice) {
            num++;
        }
    }
    for (int i = 0; i < node[index].size(); i++)
        DFS(node[index][i], depth + 1);
}

int main() {
    scanf("%d %lf %lf", &n, &p, &r);
    r = r / 100;
    for (int i = 0; i < n; i++) {
        scanf("%d", &c);
        for (int j = 0; j < c; j++) {
            scanf("%d", &x);
            node[i].push_back(x);
        }
    }
    DFS(0, 0);

    printf("%.4f %d", minPrice, num);
}

//16:30 AC