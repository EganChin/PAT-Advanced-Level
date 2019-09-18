//
// Created by Administrator on 2019/8/27.
//

/**
 * Answering at 2019/9/18 10:02
 */

/**
 *
Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3

Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0
 **/

#include <iostream>
#include <map>
#include <string>

using namespace std;

#define MAXV 2010


map<string, int> gang;
map<string, int> strToInt;
map<int, string> intToStr;

int personNum = 0, n, k;

int G[MAXV][MAXV] = {0}, weight[MAXV] = {0}, visit[MAXV] = {0};

/**
 * 将字符串转换为数字id
 **/
int convert(const string &str) {
    if (strToInt.find(str) != strToInt.end()) {
        return strToInt[str];
    } else {
        strToInt[str] = personNum;
        intToStr[personNum] = str;
        return personNum++;
    }
}

void DFS(int u, int &head, int &memberNum, int &totalValue) {
    //如果顶点没有被访问过
    if (!visit[u]) {
        visit[u] = true;
        if (weight[u] > weight[head])
            head = u;
        memberNum++;
        for (int v = 0; v < personNum; v++) {
            //如果存在通话记录，计算总时长和成员数
            if (G[u][v] > 0) {
                totalValue += G[v][u];
                //无向图，必须删除边防止回头
                G[u][v] = G[v][u] = 0;
                if (!visit[v])
                    DFS(v, head, memberNum, totalValue);
            }
        }
    }
}

void DFSTravel() {
    for (int i = 0; i < personNum; i++) {
        int head = i, memberNum = 0, totalValue = 0;
        DFS(i, head, memberNum, totalValue);
//        cout << intToStr[head] << "," << head << "," << memberNum << "," << totalValue << endl;
        //如果是一个团伙
        if (memberNum > 2 && totalValue > k) {
            gang[intToStr[head]] = memberNum;
        }
    }
}

int main() {
    int time, id1, id2;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string name1, name2;
        cin >> name1 >> name2 >> time;
        id1 = convert(name1);
        id2 = convert(name2);
        G[id1][id2] = G[id2][id1] = (G[id1][id2] + time);
        weight[id1] += time;
        weight[id2] += time;
    }
    DFSTravel();
    cout << gang.size() << endl;
    for (const auto &it: gang) {
        cout << it.first << " " << it.second << endl;
    }
}

/**
 * Accept at 2019/9/18 14:36
 */