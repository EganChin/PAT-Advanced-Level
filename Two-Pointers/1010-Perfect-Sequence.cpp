/*
1085 Perfect Sequence （25 分）
Given a sequence of positive integers and another positive integer p. The sequence is said to be a perfect sequence if M≤m×p where M and m are the maximum and minimum numbers in the sequence, respectively.

Now given a sequence and a parameter p, you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence.

Input Specification:
Each input file contains one test case. For each case, the first line contains two positive integers N and p, where N (≤10
​5
​​ ) is the number of integers in the sequence, and p (≤10
​9
​​ ) is the parameter. In the second line there are N positive integers, each is no greater than 10
​9
​​ .

Output Specification:
For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.

Sample Input:
10 8
2 3 20 4 5 1 6 7 8 9
Sample Output:
8
*/

//2019 2 23 13:00 read

//思路：对于一个范围在[i,j]的递增数列，若满足a[j]<=a[i]*p，则任意一个数k，一定也满足a[k]<=a[i]*p

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    int n, p;
    scanf("%d%d", &n, &p);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    sort(a, a+n);
    int i=0, j=0, count = 1;
    while(i<n && j<n){
        while(j<n && a[j]<=(long long)a[i]*p){
            count = max(count, j-i+1);
            j++;
        }
        i++;
    }
    printf("%d\n", count);
    return 0;
}

// end 13:19
