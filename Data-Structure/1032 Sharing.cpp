//
// Created by Administrator on 2019/8/5.
//
/**
 *
 * Sample Input 1:
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010
Sample Output 1:
67890

Sample Input 2:
00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1
Sample Output 2:
-1
 */
//2019.8.9 12:37 reading
//2019.8.9 12:42 read
#include <iostream>

using namespace std;

struct Node {
    char data;
    int next;
    bool appear;
} node[100010];

int main() {
    int begin1, begin2, n, common = -1;
    scanf("%d%d%d", &begin1, &begin2, &n);
    for(int i=0; i<n; i++){
        int address, next;
        char data;
        scanf("%d %c %d", &address, &data, &next);
        node[address].data = data;
        node[address].next = next;
        node[address].appear = false;
    }

    //遍历第一个单词链表
    int h = begin1;
    while (h != -1){
        node[h].appear = true;
        h = node[h].next;
    }

    h = begin2;
    while (h != -1){
        if(node[h].appear){
            common = h;
            break;
        }
        h = node[h].next;
    }

    printf(common==-1 ? "%d\n":"%05d\n", common);

    return 0;
}

//12:55 AC