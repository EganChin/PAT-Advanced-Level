//
// Created by Administrator on 2019/8/5.
//

//2019.8.12 15:17 reading
//2019.8.12 15:26 read


/**
Sample Input:
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854

Sample Output:
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1
**/

#include <map>
#include <iostream>
#include <cmath>
using namespace std;

struct Node{
    int key;
    int next;
}node[100010];

void print(int address){
    printf(node[address].next != -1 ? "%05d %d %05d\n" :"%05d %d %d\n", address, node[address].key, node[address].next);
}

int main(){
    map<int,int> appear;
    int begin, n, address;
    scanf("%d %d",&begin, &n);
    for(int i=0;i<n; i++){
        scanf("%d", &address);
        scanf("%d%d", &node[address].key, &node[address].next);
    }

    //特殊情况
    if(n==1){
        print(begin);
        return 0;
    }

    int begin2=-1,lastRemove=-1, h=begin,lastResult=begin;
    while (h!=-1){
        int cur = h;
        h = node[h].next;
        //key已经出现过，移除它
        if(appear[abs(node[cur].key)] != 0){
            //使上一个剩余节点指向空
            node[lastResult].next = -1;
            if(begin2==-1){
                lastRemove = begin2 = cur;
            } else{
                node[lastRemove].next = cur;
                node[cur].next = -1;
                lastRemove = cur;
            }
        }else{
            //让上一个剩余节点指向当前节点
            node[lastResult].next = cur;
            lastResult = cur;
        }
        appear[abs(node[cur].key)]++;
    }

    //输出剩余链表
    h = begin;
    while(h!=-1){
        print(h);
        h = node[h].next;
    }

    //输出被移除的链表
    h = begin2;
    while(h!=-1){
        print(h);
        h = node[h].next;
    }
}

//15:50 PAT 输出超限 NC AC
//15:58 AC 考虑n=1的特殊情况