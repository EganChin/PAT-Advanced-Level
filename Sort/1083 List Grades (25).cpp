/*
1083 List Grades （25 分）
Given a list of N student records with name, ID and grade. You are supposed to sort the records with respect to the grade in non-increasing order, and output those student records of which the grades are in a given interval.

Input Specification:
Each input file contains one test case. Each case is given in the following format:

N
name[1] ID[1] grade[1]
name[2] ID[2] grade[2]
... ...
name[N] ID[N] grade[N]
grade1 grade2
where name[i] and ID[i] are strings of no more than 10 characters with no space, grade[i] is an integer in [0, 100], grade1 and grade2 are the boundaries of the grade's interval. It is guaranteed that all the grades are distinct.

Output Specification:
For each test case you should output the student records of which the grades are in the given interval [grade1, grade2] and are in non-increasing order. Each student record occupies a line with the student's name and ID, separated by one space. If there is no student's grade in that interval, output NONE instead.

Sample Input 1:
4
Tom CS000001 59
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
60 100
Sample Output 1:
Mike CS991301
Mary EE990830
Joe Math990112
Sample Input 2:
2
Jean AA980920 60
Ann CS01 80
90 95
Sample Output 2:
NONE
*/

//2018.9.15 14:30

#include <iostream>
#include <algorithm>
using namespace std;

struct Student{
    char name[11];
    char id[11];
    int grade;
};

int cmp(Student a, Student b){
    return a.grade > b.grade;
}

int main(){
    int n;
    scanf("%d", &n);
    Student stu[n];
    for(int i=0; i<n; i++)
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);

    int grade1, grade2;
    scanf("%d %d", &grade1, &grade2);

    sort(stu, stu+n, cmp);

    bool flag = false;

    for(int i=0; i<n; i++){
        if(stu[i].grade >= grade1 && stu[i].grade <= grade2){
            printf("%s %s\n", stu[i].name, stu[i].id);
            flag = true;
        }
    }

    if(!flag)
        printf("NONE\n");

    return 0;
}

//14:42 AC
