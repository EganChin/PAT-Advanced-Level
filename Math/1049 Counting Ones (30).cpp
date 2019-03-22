/*
1049 Counting Ones （30 分)
The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.

Input Specification:
Each input file contains one test case which gives the positive N (≤2
​30
​​ ).

Output Specification:
For each test case, print the number of 1's in one line.

Sample Input:
12
Sample Output:
5
*/

//2019.3.22 19:42 reading
/*
从低到高枚举每一位，
以curr代表当前位的数字，
high代表当前位左边的高位数字，
low代表当前位左边的地位数字，a = 当前位的倍数，则
    curr = 0, ans += high * a;
    curr = 1, ans += high * a + low + 1
    curr > 1, ans += (high+1)*a
*/

#include<iostream>
using namespace std;

int main(){
    int n, a=1, ans = 0;
    int curr, low, high;
    scanf("%d", &n);
    while(n/a){
        curr = n/a%10;
        low = n%a;
        high = n/(a*10);

        if(!curr)
            ans += high * a;
        else if(curr == 1)
            ans += high * a + low + 1;
        else
            ans += (high+1)*a;
        a*=10;
        //printf("curr=%d,low=%d,high=%d, ans=%d\n",curr,low,high, ans);
    }
    printf("%d\n", ans);
    return 0;
}

//20:15 AC

