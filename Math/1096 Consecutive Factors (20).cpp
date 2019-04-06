/*
1096 Consecutive Factors （20 分)
Among all the factors of a positive integer N, there may exist several consecutive numbers. For example, 630 can be factored as 3×5×6×7, where 5, 6, and 7 are the three consecutive numbers. Now given any positive N, you are supposed to find the maximum number of consecutive factors, and list the smallest sequence of the consecutive factors.

Input Specification:
Each input file contains one test case, which gives the integer N (1<N<2
​31
​​ ).

Output Specification:
For each test case, print in the first line the maximum number of consecutive factors. Then in the second line, print the smallest sequence of the consecutive factors in the format factor[1]*factor[2]*...*factor[k], where the factors are listed in increasing order, and 1 is NOT included.

Sample Input:
630
Sample Output:
3
5*6*7
*/

//2019 4.6 13:58 reading
//2019 4.6 14:04 read

#include<iostream>
#include<cmath>
using namespace std;

typedef long long LL;

int main()
{
    LL n;
    scanf("%d", &n);
    //连续序列长度和序列的第一个数
    LL len = 0, first = 0;
    for(LL i=2; i<=(LL)sqrt(n*1.0); i++){
        LL accumulate = 1, j=i;
        //开始寻找连续序列
        while(1){
            accumulate *= j;
            //如果累积不是因子，剪枝结束循环
            if(n%accumulate != 0)   break;
            //判断当前序列长度
            if(j-i+1 > len){
                //更新长度和起始数
                len = j-i+1;
                first = i;
            }
            j++;
        }
    }

    //如果始终未找到连续序列，说明最长序列为n本身
    if(!len){
        printf("1\n%lld\n", n);
    }else{
        //最大长度
        printf("%lld\n", len);
        for(LL i=0; i<len; i++){
            printf("%lld", first+i);
            if(i!=len-1)
                printf("*");
        }
        printf("\n");
    }
    return 0;
}

//14:14 AC
