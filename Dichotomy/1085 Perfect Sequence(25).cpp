/*
1085 Perfect Sequence （25 分）
Given a sequence of positive integers and another positive integer p.

The sequence is said to be a perfect sequence if M≤m×p where M and m are the maximum and minimum numbers in the sequence, respectively.

Now given a sequence and a parameter p,

you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence.

Input Specification:
Each input file contains one test case. For each case, the first line contains two positive integers N and p,

where N (≤10^​5) is the number of integers in the sequence, and p (≤10^9) is the parameter.

In the second line there are N positive integers, each is no greater than 10^9.

Output Specification:
For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.

Sample Input:s ff
10 8
2 3 20 4 5 1 6 7 8 9
Sample Output:
8
*/

//2018.10.1
//8:48 reading
//8:56 read

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int n, p, a[maxn];

int binarySearch(int begin, long long x){
    if(a[n-1] <= x) return n;
    int left = begin+1, right = n-1, mid;
    while(left < right){
        mid = (left+right)/2;
        if(a[mid] <= x)
            left = mid+1;
        else
            right = mid;
    }

    return left;
}

int main()
{
    scanf("%d%d", &n, &p);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    sort(a, a+n);
    int ans = 1;
    for(int i=0; i<n; i++){
        int j = binarySearch(i, (long long)a[i]*p);
        ans = max(ans, j-i);
    }
    printf("%d\n", ans);
    return 0;
}

//9:15 PAUSING
