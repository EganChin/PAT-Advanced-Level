/*
1033 To Fill or Not to Fill （25 分）
With highways available, driving a car from Hangzhou to any other city is easy.

But since the tank capacity of a car is limited,

we have to find gas stations on the way from time to time.

Different gas station may give different price. You are asked to carefully design the cheapest route to go.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive numbers:

    Cmax(≤ 100), the maximum capacity of the tank;
    D (≤30000), the distance between Hangzhou and the destination city;
    Davg(≤20), the average distance per unit gas that the car can run;
    and N (≤ 500), the total number of gas stations.

Then N lines follow, each contains a pair of non-negative numbers: Pi, the unit gas price,

and Di(≤D), the distance between this station and Hangzhou, for i=1,……,N. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the cheapest price in a line,

accurate up to 2 decimal places.

It is assumed that the tank is empty at the beginning.

If it is impossible to reach the destination,

print The maximum travel distance = X where X is the maximum possible distance the car can run,

accurate up to 2 decimal places.

Sample Input 1:
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
Sample Output 1:
749.17
Sample Input 2:
50 1300 12 2
7.10 0
7.00 600
Sample Output 2:
The maximum travel distance = 1200.00
*/

#include<cstdio>
#include<algorithm>

const int maxn = 510;
const int INF = 1000000000;

struct Station{
    double price;
    double distance;
}sta[maxn];

int cmp(Station a, Station b){
    return a.distance < b.distance;
}

int main()
{
    int n;
    double cmax, d, davg;
    scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
    for(int i=0; i<n; i++){
        scanf("%lf%lf", &sta[i].price, &sta[i].distance);
    }
    //设置终点
    sta[n].distance = d,sta[n].price = 0;
    std::sort(sta, sta+n, cmp);
    if(sta[0].distance){
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }

    double tank = 0, cost = 0, minP;    //当前油量，花费，最小油价
    int now = 0, next;    //当前加油站，下一个加油站
    while(now < n){
        next = -1, minP = INF;
        //寻找下个油价更低的加油站
        for(int i=now+1; i<=n && sta[i].distance - sta[now].distance <= cmax*davg; i++){
            if(sta[i].price < minP){
                next = i;
                minP = sta[i].price;
                //如果找到一个比当前站价格更低的，结束循环
                if(minP < sta[now].price)
                    break;
            }

        }
        //找不到加油站
        if(next == -1)   break;
        //到下一站需要的油量
        double need = (sta[next].distance - sta[now].distance) / davg;

        //如果找到的加油站油价比当前站低
        if(minP < sta[now].price){
            //油量不足
            if(need > tank){
                cost += (need - tank) * sta[now].price;
                tank = 0;
            }else   //油量充足，不加油
                tank -= need;
        }else{
            //油价高于当前站，加满油箱
            cost += (cmax - tank) * sta[now].price;
            tank = cmax - need;

        }
        now = next;
    }

    if(now == n){
        //可以到达终点
        printf("%.2f\n", cost);
    }else{
        printf("The maximum travel distance = %.2f\n", sta[now].distance + cmax*davg);
    }

    return 0;
}
