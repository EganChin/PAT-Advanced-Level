/*
To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algebra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

For example, The grades of C, M, E and A - Average of 4 students are given as the following:

StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

Input

Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (<=2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.

Output

For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

If a student is not on the grading list, simply output "N/A".

Sample Input

5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output

1 C
1 M
1 E
1 A
3 A
N/A
*/

//2018.7.25 22:46 Reading Question
//2018.7.25 22:56 Answering Question
//2018.7.25 23:08 Pausing
//2018.7.25 23:38 Restarting

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX 999999

typedef struct{
    int id;
    int grade[4];
}Student;

int now, N, M, ranklist[MAX][4];

char courses[4] = {'A', 'C', 'M', 'E'};

int cmp(Student a, Student b)
{
    return a.grade[now] > b.grade[now];
}


int main()
{
    scanf("%d%d", &N, &M);
    Student stus[N];
    for(int i = 0; i<N; i++){
        scanf("%d%d%d%d", &stus[i].id, &stus[i].grade[1], &stus[i].grade[2], &stus[i].grade[3]);
        stus[i].grade[0] = (stus[i].grade[1] + stus[i].grade[2] + stus[i].grade[3])/3;
        
    }
    //Evaluating Four Ranks
    for(now=0; now<4; now++){
        sort(stus, stus+N, cmp);
        ranklist[stus[0].id][now] = 1;
        for(int i=1; i<N; i++){
            if(stus[i].grade[now] == stus[i-1].grade[now])
                ranklist[stus[i].id][now] = ranklist[stus[i-1].id][now];
            else
                ranklist[stus[i].id][now] = i+1;
        }
    }

    while(M--){
        int id, maxG, maxR;
        scanf("%d", &id);
        int high = 0;
        for(int i=0; i<4; i++)
            if(ranklist[id][i] < ranklist[id][high])
                high = i;
        if(ranklist[id][high] == 0)
            printf("N/A\n");
        else
            printf("%d %c\n", ranklist[id][high], courses[high]);        
                
    }
    system("PAUSE");
    return 0;
}

//2018.7.26 0:43 WA
//2018.7.26 1:05 AC
