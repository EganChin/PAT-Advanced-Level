//
// Created by Administrator on 2019/8/5.
//
/**
Sample Input:
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345

Sample Output:
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1


6 00000
00000 1 11111
11111 2 22222
22222 3 -1
33333 4 44444
44444 5 55555
55555 6 -1
**/

//2019.8.9 13:17 reading
//2019.8.9 13:22 read

#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int data;
    int next;
}node[100010];

int cmp(int a, int b){
    return node[a].data < node[b].data;
}

int main(){
    int n, begin;
    scanf("%d%d", &n, &begin);
    int index[n];
    for(int i=0;i<n;i++){
        int address,data,next;
        scanf("%d%d%d",&address,&data,&next);
        node[address].data = data;
        node[address].next = next;
    }
    index[0] = -1;
    int h = begin, count=0;
    while (h!=-1){
        index[count++] = h;
        h = node[h].next;
    }
    sort(index, index+count, cmp);
    printf(index[0]!=-1 ? "%d %05d\n" : "%d %d\n", count, index[0]);
    for(int i=0; i<count; i++){
        if(i==count-1){
            printf("%05d %d -1\n",index[i], node[index[i]].data);
        } else{
            printf("%05d %d %05d\n",index[i], node[index[i]].data, index[i+1]);
        }
    }
}

//13:44 AC