/*
1075 PAT Judge （25 分）
The ranklist of PAT is generated from the status list, which shows the scores of the submissions. This time you are supposed to generate the ranklist for PAT.

Input Specification:
Each input file contains one test case. For each case, the first line contains 3 positive integers, N (≤10
​4
​​ ), the total number of users, K (≤5), the total number of problems, and M (≤10
​5
​​ ), the total number of submissions. It is then assumed that the user id's are 5-digit numbers from 00001 to N, and the problem id's are from 1 to K. The next line contains K positive integers p[i] (i=1, ..., K), where p[i] corresponds to the full mark of the i-th problem. Then M lines follow, each gives the information of a submission in the following format:

user_id problem_id partial_score_obtained
where partial_score_obtained is either −1 if the submission cannot even pass the compiler, or is an integer in the range [0, p[problem_id]]. All the numbers in a line are separated by a space.

Output Specification:
For each test case, you are supposed to output the ranklist in the following format:

rank user_id total_score s[1] ... s[K]
where rank is calculated according to the total_score, and all the users with the same total_score obtain the same rank; and s[i] is the partial score obtained for the i-th problem. If a user has never submitted a solution for a problem, then "-" must be printed at the corresponding position. If a user has submitted several solutions to solve one problem, then the highest score will be counted.

The ranklist must be printed in non-decreasing order of the ranks. For those who have the same rank, users must be sorted in nonincreasing order according to the number of perfectly solved problems. And if there is still a tie, then they must be printed in increasing order of their id's. For those who has never submitted any solution that can pass the compiler, or has never submitted any solution, they must NOT be shown on the ranklist. It is guaranteed that at least one user can be shown on the ranklist.

Sample Input:
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
Sample Output:
1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -

4 3 8
20 30 40
00001 1 15
00001 3 20
00002 2 0
00002 3 0
00003 1 20
00003 2 15
00004 1 -1
00004 3 -1
*/

//2018.9.14 8:40 Start
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_N 10010
#define MAX_K 5

int n, k, m, fullMark[MAX_K];

struct Student{
    int id;
    int score[MAX_K];
    bool compilable;
    int total;
    int perfect;
}stu[MAX_N];

int cmp(Student a, Student b){
    if(a.compilable != b.compilable)    return a.compilable > b.compilable;
    else if(a.total != b.total) return a.total > b.total;
    else if(a.perfect != b.perfect) return a.perfect > b.perfect;
    return a.id < b.id;
}

void init(){
    for(int i=0; i<n; i++){
        stu[i].id = i+1;
        stu[i].compilable = false;
        stu[i].perfect = 0;
        stu[i].total = 0;
        memset(stu[i].score, -1, sizeof(stu[i].score));
    }
}

int main(){

    scanf("%d%d%d", &n, &k, &m);
    for(int i=0; i<k; i++)
        scanf("%d", &fullMark[i]);

    init();

    for(int i=0; i<m; i++){
        int u_id, p_id, score;
        scanf("%d%d%d", &u_id, &p_id, &score);
        u_id -= 1;  p_id -= 1;
        //如果有可通过编译的题目，记为可输出
        if(score != -1)
            stu[u_id].compilable = true;
        //如果该题第一次提交未通过编译，记为0分
        if(score == -1 && stu[u_id].score[p_id] == -1)
            stu[u_id].score[p_id] = 0;
        //获得满分，完美题数加一，注意判断当前分数是否满分，否则会重复累计
        if(score == fullMark[p_id] && stu[u_id].score[p_id] < fullMark[p_id])
            stu[u_id].perfect++;
        //如果当前得分高于原来分数，覆盖
        if(score > stu[u_id].score[p_id])
            stu[u_id].score[p_id] = score;
    }

    //计算总分
    for(int i=0; i<n; i++)
        for(int j=0; j<k; j++)
            if(stu[i].score[j] != -1)
                stu[i].total += stu[i].score[j];

    sort(stu, stu+n, cmp);

    int rank = 1;
    for(int i=0; i<n && stu[i].compilable; i++){
        if(i && stu[i].total != stu[i-1].total)
            rank = i+1;
        printf("%d %05d %d", rank, stu[i].id, stu[i].total);

        for(int j=0; j<k; j++)
            stu[i].score[j] == -1 ? printf(" -") : printf(" %d", stu[i].score[j]);
        printf("\n");

    }
    return 0;
}

//9:49 AC
