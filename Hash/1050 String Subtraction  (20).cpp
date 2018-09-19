/*
1050 String Subtraction （20 分）

Given two strings S1 and S2,

S=S1−S2is defined to be the remaining string after taking all the characters in S2 from S1.

Your task is simply to calculate S1−S2 for any given strings.

However, it might not be that simple to do it fast.

Input Specification:
Each input file contains one test case.

Each case consists of two lines which gives S1 and S2,

respectively. The string lengths of both strings are no more than 10^4.

It is guaranteed that all the characters are visible ASCII codes and white space,

and a new line character signals the end of a string.

Output Specification:
For each test case, print S1−S2 in one line.

Sample Input:
They are students.
aeiou
Sample Output:
Thy r stdnts.
*/

//2018.9.19 9:08 reading
//9:13 read

#include <stdio.h>
#include <string.h>

const int maxlen = 10010;

int main(){
    char str1[maxlen], str2[maxlen];
    int hash[128] = {0};

    gets(str1);
    gets(str2);
    int len1 = strlen(str1), len2 = strlen(str2);
    for(int i=0; i<len1; i++)
        hash[str1[i]]++;
    for(int i=0; i<len2; i++)
        hash[str2[i]] = 0;
    for(int i=0; i<len1; i++)
        if(hash[str1[i]])
            printf("%c", str1[i]);
    printf("\n");
    return 0;
}

//9:26 AC
