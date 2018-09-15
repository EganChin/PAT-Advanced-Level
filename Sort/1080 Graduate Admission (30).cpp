/*
1080 Graduate Admission （30 分）
It is said that in 2011, there are about 100 graduate schools ready to proceed over 40,000 applications in Zhejiang Province. It would help a lot if you could write a program to automate the admission procedure.

Each applicant will have to provide two grades: the national entrance exam grade GE, and the interview grade GI.
The final grade of an applicant is (GE+GI)/2. The admission rules are:

    The applicants are ranked according to their final grades, and will be admitted one by one from the top of the rank list.

    If there is a tied final grade, the applicants will be ranked according to their national entrance exam grade GE
​​.If still tied, their ranks must be the same.

    Each applicant may have K choices and the admission will be done according to his/her choices:
if according to the rank list, it is one's turn to be admitted; and if the quota of one's most preferred shcool is not exceeded,
then one will be admitted to this school, or one's other choices will be considered one by one in order.
If one gets rejected by all of preferred schools, then this unfortunate applicant will be rejected.

If there is a tied rank, and if the corresponding applicants are applying to the same school,
then that school must admit all the applicants with the same rank, even if its quota will be exceeded.

Input Specification:
Each input file contains one test case.

    Each case starts with a line containing three positive integers:
    N (≤40,000), the total number of applicants;
    M (≤100), the total number of graduate schools;
    and K (≤5), the number of choices an applicant may have.

In the next line, separated by a space, there are M positive integers. The i-th integer is the quota of the i-th graduate school respectively.

Then N lines follow, each contains 2+K integers separated by a space. The first 2 integers are the applicant's GE and GI
​​ , respectively. The next K integers represent the preferred schools. For the sake of simplicity,
we assume that the schools are numbered from 0 to M−1, and the applicants are numbered from 0 to N−1.

Output Specification:
For each test case you should output the admission results for all the graduate schools.
The results of each school must occupy a line, which contains the applicants' numbers that school admits.
The numbers must be in increasing order and be separated by a space.
There must be no extra space at the end of each line. If no applicant is admitted by a school, you must output an empty line correspondingly.

Sample Input:
11 6 3
2 1 2 2 2 3
100 100 0 1 2
60 60 2 3 5
100 90 0 3 4
90 100 1 2 0
90 90 5 1 3
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4
Sample Output:
0 10
3
5 6 7
2 8

1 4
*/

//2018.9.15
//15:04 reading
//15:09 read completely

//注意：只要考生的排名和当前的志愿院校的最后录取学生排名相同，则可被超额录取
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=40010, MAX_M=110, MAX_K=5;

int n, m, k, quota[MAX_M];

struct Student{
    //学生id, 排名，总分，GE, GI，志愿
    int id, rank, sum, ge, gi, choice[MAX_K];
}stu[MAX_N];

struct School{
    //实招人数，限额，学生id，最后一名学生的Id
    int num, quota, stuId[MAX_N], lastAdmit;
}sch[MAX_M];

int cmpGrd(Student a, Student b)
{
    return a.sum != b.sum ? a.sum > b.sum : a.ge > b.ge;
}

int cmpId(int a, int b){
    return stu[a].id < stu[b].id;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0; i<m; i++){
        scanf("%d", &sch[i].quota);
        sch[i].num = 0;
        sch[i].lastAdmit = -1;
    }

    for(int i=0; i<n; i++){
        scanf("%d%d", &stu[i].ge, &stu[i].gi);
        stu[i].sum = stu[i].ge + stu[i].gi;
        stu[i].id = i;
        for(int j=0; j<k; j++)
            scanf("%d", &stu[i].choice[j]);
    }

    sort(stu, stu+n, cmpGrd);

    //计算排名
    for(int i=0; i<n; i++){
        stu[i].rank =
        (i && stu[i-1].sum==stu[i].sum && stu[i-1].ge == stu[i].ge ) ?
            stu[i-1].rank : i+1;
    }

    //开始录取
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            int choice = stu[i].choice[j];
            int last = sch[choice].lastAdmit;
            if(sch[choice].num < sch[choice].quota || (last != -1 && stu[last].rank == stu[i].rank)){
                sch[choice].stuId[sch[choice].num++] = sch[choice].lastAdmit = i;
                break; //当前考生被成功录取
            }
        }
    }

    //公布每所院校的录取结果
    for(int i=0; i<m; i++){
        sort(sch[i].stuId, sch[i].stuId+sch[i].num, cmpId);
        if(sch[i].num > 0){
            for(int j=0; j<sch[i].num; j++){
                printf("%d", stu[sch[i].stuId[j]].id);
                if(j < sch[i].num - 1)
                    printf(" ");
            }
        }
        printf("\n");
    }
}
