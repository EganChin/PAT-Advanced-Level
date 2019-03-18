/*
1101 Quick Sort （25 分)
There is a classical process named partition in the famous quick sort algorithm. In this process we typically choose one element as the pivot. Then the elements less than the pivot are moved to its left and those larger than the pivot to its right. Given N distinct positive integers after a run of partition, could you tell how many elements could be the selected pivot for this partition?

For example, given N=5 and the numbers 1, 3, 2, 4, and 5. We have:

1 could be the pivot since there is no element to its left and all the elements to its right are larger than it;
3 must not be the pivot since although all the elements to its left are smaller, the number 2 to its right is less than it as well;
2 must not be the pivot since although all the elements to its right are larger, the number 3 to its left is larger than it as well;
and for the similar reason, 4 and 5 could also be the pivot.
Hence in total there are 3 pivot candidates.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤10
​5
​​ ). Then the next line contains N distinct positive integers no larger than 10
​9
​​ . The numbers in a line are separated by spaces.

Output Specification:
For each test case, output in the first line the number of pivot candidates. Then in the next line print these candidates in increasing order. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.

Sample Input:
5
1 3 2 4 5
Sample Output:
3
1 4 5
*/

//2019.3.18 15:09 reading
//15:14 read

#include<iostream>
#include<algorithm>
using namespace std;

const int INF = (1<<31)-1;

int main(){
    int n;
    scanf("%d", &n);
    int A[n+10], leftMax[n+10], rightMin[n+10],count=0;
    //最后一个元素的左边的最大元素是0
    leftMax[0] = 0;
    for(int i=0;i<n;i++){
        scanf("%d", &A[i]);
        //存储A[i]左边最小的元素
        if(i==1)
            leftMax[i] = A[i-1];
        else if(i>1)
            leftMax[i] = max(A[i-1], leftMax[i-1]);
    }
    //最后一个元素的右边的最小元素是无限大
    rightMin[n-1] = INF;
    //从右到左遍历，存储右边最小的元素
    for(int i=n-1;i>=0;i--){
        if(i==n-2)
            rightMin[i] = A[n-1];
        else if(i<n-2)
            rightMin[i] = min(A[i+1], rightMin[i+1]);

        //printf("A[%d]=%d, leftMax=%d, rightMin=%d ", i, A[i], leftMax[i], rightMin[i]);

        //同时计算满足条件的主元的个数
        if(A[i]<=rightMin[i] && A[i]>=leftMax[i]){
            //printf("pivot=%d", A[i]);
            count++;
        }
        //printf("\n");
    }

    printf("%d\n",count);

    for(int i=0,cnt=0; i<n;i++){
        if(A[i]<=rightMin[i] && A[i]>=leftMax[i]){
            if(cnt++==0)
                printf("%d", A[i]);
            else
                printf(" %d", A[i]);
        }
    }
    printf("\n");
    return 0;
}

//15:41 AC
