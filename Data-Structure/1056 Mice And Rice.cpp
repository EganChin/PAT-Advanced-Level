//
// Created by Administrator on 2019/8/5.
//

//2019.8.5 17:13 reading
//2019.8.6 14:58 read

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Mouse {
    int rank;
    int weight;
};

int main() {
    int np, ng, order;
    scanf("%d%d", &np, &ng);
    Mouse mouse[np];

    queue<int> q;

    for (int i = 0; i < np; i++)
        scanf("%d", &mouse[i].weight);
    for (int i = 0; i < np; i++) {
        scanf("%d", &order);
        q.push(order);
    }

    //本轮总老鼠数和组数
    int num = np, group;
    //最后一只老鼠特殊处理
    while (q.size() > 1) {
        group = num % ng == 0 ? num / ng : num / ng + 1;
        //找出每一组的晋级者
        for(int g=0; g<group;g++){
            int winner = q.front();
            //本组总数不足ng，结束循环
//            printf("%d", q.front());
            for(int m=0; m<ng && g*ng+m<num; m++){
                if(mouse[q.front()].weight > mouse[winner].weight)
                    winner = q.front();
                mouse[q.front()].rank = group+1;
                q.pop();
            }
            q.push(winner);
        }
        //每组有一只老鼠晋级
        num = group;
    }
    //最后一只老鼠排名1
    mouse[q.front()].rank = 1;

    for(int i=0; i<np; i++){
        printf("%d", mouse[i].rank);
        if(i<np-1)
            printf(" ");
    }

    return 0;
}

//15:40 AC