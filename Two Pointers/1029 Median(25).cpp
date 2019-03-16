/*
1029 Median （25 分)
Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1 = { 11, 12, 13, 14 } is 12, and the median of S2 = { 9, 10, 15, 16, 17 } is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.

Given two increasing sequences of integers, you are asked to find their median.

Input Specification:
Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (≤2×10
​5
​​ ) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.

Output Specification:
For each test case you should output the median of the two given sequences in a line.

Sample Input:
4 11 12 13 14
5 9 10 15 16 17
Sample Output:
13
*/

//19.3.16 21L04 reading
//21L09 read

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int INF = (1<<31)-1;

int main()
{
    int n1,n2;
    scanf("%d", &n1);
    int S1[n1+10],S2;
    for(int i=0;i<n1; i++)
        scanf("%d", &S1[i]);
    S1[n1] = INF;
    scanf("%d%d", &n2,&S2);
    int i=0,j=0,count=0, mid = (n1+n2-1)/2;
    while(count++<mid){
        if(S1[i]<S2){
            i++;
        }
        else{
            j++;
            if(j<n2)
                scanf("%d", &S2);
            else if(j==n2)
                S2 = INF;
            else
                break;
        }
    }
    //由于最后一趟循环未比较大小，因此输出时需要再比较一次
    printf("%d\n", S1[i]<S2?S1[i]:S2);

}

//21:24 内存超限
//22:04 AC

/*
如果将所有数据读入内存，会导致内存超限
应使用双指针法解题，序列S1存储所有数据，但S2只保存一个最新的数，边输入边比较
根据序列合并思想，只有当S1[i]<S2时，才需要i自增，否则j自增
为防止出现因两个序列长度不一导致访问越界问题，应将每个序列的最后一个元素设为可能的最大值
*/
