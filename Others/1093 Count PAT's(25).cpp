/*
1093 Count PAT's （25 分)
The string APPAPT contains two PAT's as substrings. The first one is formed by the 2nd, the 4th, and the 6th characters, and the second one is formed by the 3rd, the 4th, and the 6th characters.

Now given any string, you are supposed to tell the number of PAT's contained in the string.

Input Specification:
Each input file contains one test case. For each case, there is only one line giving a string of no more than 10
​5
​​  characters containing only  P, A, or T.

Output Specification:
For each test case, print in one line the number of PAT's contained in the string. Since the result may be a huge number, you only have to output the result moded by 1000000007.

Sample Input:
APPAPT
Sample Output:
2
*/

//20190318 14:12

#include<iostream>
#include<cstring>
using namespace std;

#define MAXLEN 100010

int leftNum[MAXLEN] = {0};
char str[MAXLEN];

int main()
{
    //string str;
    gets(str);
    int len = strlen(str);
    for(int i=0; i<len; i++){
        if(i>0)
            leftNum[i] = leftNum[i-1];
        if(str[i] == 'P')
            leftNum[i]++;
    }
    int ans = 0, rightNum = 0;
    for(int i=len-1; i>=0; i--){
        if(str[i] == 'T')
            rightNum++;
        else if(str[i] == 'A')
            ans = (ans +(leftNum[i]*rightNum)) % 1000000007;
    }

    cout << ans << endl;
    return 0;
}


//14:26 AC 注意要对结果正确取余
