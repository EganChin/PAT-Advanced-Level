//
// Created by Administrator on 2019/8/12.
//

/**
Sample Input:
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0

Sample Output:
26
**/

//2019.8.13 17:26 reading
//2019.8.13 17:35 read

#include <queue>
#include <iostream>

using namespace std;

struct node {
    int x, y, z;
} Node;

int n, m, l, t;

int pixel[1290][130][61];
bool inq[1290][130][61] = {false};

int X[] = {0, 0, 0, 0, 1, -1};
int Y[] = {0, 0, 1, -1, 0, 0};
int Z[] = {1, -1, 0, 0, 0, 0};

bool judge(int x, int y, int z) {
    if (x >= n || x < 0 || y >= m || y < 0 || z >= l || z < 0) return false;

    if (pixel[x][y][z] == 0 || inq[x][y][z]) return false;

    return true;
}

int BFS(int x, int y, int z) {
    int oneCount = 0;   //当前块中1的个数
    queue<node> q;
    Node.x = x, Node.y = y, Node.z = z;
    q.push(Node);
    inq[x][y][z] = true;
    while (!q.empty()) {
        node top = q.front();
        q.pop();
        oneCount++;
        for (int i = 0; i < 6; i++) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            int newZ = top.z + Z[i];
            if (judge(newX, newY, newZ)) {
                Node.x = newX, Node.y = newY, Node.z = newZ;
                q.push(Node);
                inq[newX][newY][newZ] = true;
            }
        }
    }
    if (oneCount >= t) return oneCount;
    else return 0;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &l, &t);
    for (int z = 0; z < l; z++)
        for (int x = 0; x < n; x++)
            for (int y = 0; y < m; y++)
                scanf("%d", &pixel[x][y][z]);

    int ans = 0;
    for (int z = 0; z < l; z++)
        for (int x = 0; x < n; x++)
            for (int y = 0; y < m; y++)
                if (pixel[x][y][z] == 1 && !inq[x][y][z])
                    ans += BFS(x, y, z);

    printf("%d", ans);
}

//17:50 AC