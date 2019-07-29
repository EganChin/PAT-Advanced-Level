//
// Created by Administrator on 2019/7/29.
//

/**
 Given two sets of integers, the similarity of the sets is defined to be N
​c
​​ /N
​t
​​ ×100%, where N
​c
​​  is the number of distinct common numbers shared by the two sets, and N
​t
​​  is the total number of distinct numbers in the two sets. Your job is to calculate the similarity of any given pair of sets.

Input Specification:
Each input file contains one test case. Each case first gives a positive integer N (≤50) which is the total number of sets. Then N lines follow, each gives a set with a positive M (≤10
​4
​​ ) and followed by M integers in the range [0,10
​9
​​ ]. After the input of sets, a positive integer K (≤2000) is given, followed by K lines of queries. Each query gives a pair of set numbers (the sets are numbered from 1 to N). All the numbers in a line are separated by a space.

Output Specification:
For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.

Sample Input:
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
Sample Output:
50.0%
33.3%
 * **/

//2019.7.29 15:55 reading
//2019.7.29 16:01 read

#include <set>
#include <vector>
#include <iostream>

using namespace std;

int main() {

    int n, m, k, x;
    scanf("%d", &n);

    set<int> sets[n+10];

    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; ++j) {
            scanf("%d", &x);
            sets[i].insert(x);
        }
    }

    scanf("%d", &k);

    for (int i = 0; i < k; ++i) {
        int q1, q2;
        scanf("%d%d", &q1, &q2);
        set<int> set1 = sets[q1], set2 = sets[q2];
        float total = set2.size(), same = 0;
        for(auto &it : set1){
            if(set2.find(it) != set2.end())
                same++;
            else
                total++;
        }

        printf("%.1f%%\n", same*100/total);
    }
}

//16:41 AC