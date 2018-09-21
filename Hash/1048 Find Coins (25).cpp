/*
1048 Find Coins （25 分）
Eva loves to collect coins from all over the universe, including some other planets like Mars.

One day she visited a universal shopping mall which could accept all kinds of coins as payments.

However, there was a special requirement of the payment: for each bill, she could only use exactly two coins to pay the exact amount.

Since she has as many as 10^5 coins with her, she definitely needs your help.

You are supposed to tell her, for any given amount of money, whether or not she can find two coins to pay for it.

Input Specification:

Each input file contains one test case. For each case,

the first line contains 2 positive numbers: N (≤10^5, the total number of coins)

and M (≤10^3), the amount of money Eva has to pay).

The second line contains N face values of the coins, which are all positive numbers no more than 500.

All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the two face values V1 and V2
​​  (separated by a space) such that V1+V2=M and V1≤V2.

If such a solution is not unique, output the one with the smallest V1.

If there is no solution, output No Solution instead.

Sample Input 1:
8 15
1 2 8 7 2 4 11 15
Sample Output 1:
4 11
Sample Input 2:
7 14
1 8 7 2 4 11 15
Sample Output 2:
No Solution
*/
#include <stdio.h>

const int maxm = 1010;

int main(){

    int n, m, hashtable[maxm] = {0};
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        int num;
        scanf("%d", &num);
        hashtable[num]++;
    }
    for(int i=1; i<m; i++)
        if(hashtable[i] && hashtable[m-i]){
            //避免重复计算
            if(i==m-i && hashtable[i] < 2)
                continue;
            printf("%d %d\n", i, m-i);
            return 0;
        }
    printf("No Solution\n");
    return 0;
}

// 2018.9.20 finish
