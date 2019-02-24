/*
1044 Shopping in Mars （25 分）
Shopping in Mars is quite a different experience. The Mars people pay by chained diamonds. Each diamond has a value (in Mars dollars M$).

When making the payment, the chain can be cut at any position for only once and some of the diamonds are taken off the chain one by one.

Once a diamond is off the chain, it cannot be taken back. For example,

if we have a chain of 8 diamonds with values M$3, 2, 1, 5, 4, 6, 8, 7, and we must pay M$15. We may have 3 options:

Cut the chain between 4 and 6, and take off the diamonds from the position 1 to 5 (with values 3+2+1+5+4=15).
Cut before 5 or after 6, and take off the diamonds from the position 4 to 6 (with values 5+4+6=15).
Cut before 8, and take off the diamonds from the position 7 to 8 (with values 8+7=15).
Now given the chain of diamond values and the amount that a customer has to pay, you are supposed to list all the paying options for the customer.

If it is impossible to pay the exact amount, you must suggest solutions with minimum lost.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 numbers: N (≤10^5), the total number of diamonds on the chain, and M (≤10^8),

the amount that the customer has to pay. Then the next line contains N positive numbers D1...Dn(D​i≤10^​3 for all i=1,⋯,N) which are the values of the diamonds.

All the numbers in a line are separated by a space.

Output Specification:
For each test case, print i-j in a line for each pair of i ≤ j such that Di + ... + Dj = M. Note that if there are more than one solution,

all the solutions must be printed in increasing order of i.

If there is no solution, output i-j for pairs of i ≤ j such that Di + ... + Dj >M with (Di + ... + Dj −M) minimized.

Again all the solutions must be printed in increasing order of i.

It is guaranteed that the total value of diamonds is sufficient to pay the given amount.

Sample Input 1:
16 15
3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13
#3 5 6 11 15 21 29 36 52 62 78 89 98 110 124 137
Sample Output 1:
1-5
4-6
7-8
11-11
Sample Input 2:
5 13
2 4 5 7 9
#2 6 11 18 27
Sample Output 2:
2-4
4-5
*/

//20190129 19:26 read

//20190207 21:14 start

#include<cstdio>
#include<cstdlib>

#define MAX_M 100000010
#define MAX_N 100010

int sum[MAX_N];

//找到sum[L, R]范围内第一个大或等于x的数的位置
int lower_bound(int L, int R, int x){
    int median = (L+R)/2;
    while(L<R){
        median = (L+R)/2;
        if(sum[median] >= x)
            R = median;
        else
            L = median + 1;
    }
    return L;
}

int main(){
    int n, m, nearM = MAX_M;

    scanf("%d%d", &n, &m);

    //为方便计算，令sum[0]为零，sum[i]=sum[1]+sum[2]+...+sum[i-1];
    for(int i=1; i<=n; i++){
        scanf("%d", &sum[i]);
        sum[i] += sum[i-1];

    }

    //枚举左端点
    for(int l=1; l<=n; l++){
        //找到右端点，一般输入范围为[0,n],由于l从1开始，所以r=n+1
        int r = lower_bound(l, n+1, sum[l-1]+m);
        //printf("right:%d,%d,%d\n", r, sum[r],nearM);
        //价格正好合适，结束查找
        if(sum[r] - sum[l-1] == m){
            nearM = m;
            break;
        }else if(r <= n && sum[r] - sum[l-1] < nearM){
            nearM = sum[r] - sum[l-1];
        }
    }

    //寻找满足nearM的结果
    for(int l=1; l<=n; l++){
        int r = lower_bound(l, n+1, sum[l-1]+m);
        if(sum[r] - sum[l-1] == nearM)
            printf("%d-%d\n", l, r);
    }

}

// end 21:48
