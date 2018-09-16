/*
1084 Broken Keyboard （20 分）
On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters corresponding to those keys will not appear on screen.

Now given a string that you are supposed to type, and the string that you actually type out, please list those keys which are for sure worn out.

Input Specification:
Each input file contains one test case. For each case, the 1st line contains the original string, and the 2nd line contains the typed-out string. Each string contains no more than 80 characters which are either English letters [A-Z] (case insensitive), digital numbers [0-9], or _ (representing the space). It is guaranteed that both strings are non-empty.

Output Specification:
For each test case, print in one line the keys that are worn out, in the order of being detected. The English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed that there is at least one worn out key.

Sample Input:
7_This_is_a_test
_hs_s_a_es
Sample Output:
7TI
*/

//2018.9.16

#include <iostream>
#include <cstring>
using namespace std;

char toUpper(char c){
    return (c>='a' && c<='z') ? c-'a'+'A' : c;
}

int main(){
    char str1[88];
    char str2[88];
    bool isPrint[128] = {false};    //字符是否被输出过
    scanf("%s", str1);
    getchar();
    scanf("%s", str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for(int i=0 ,j; i<len1; i++){
        char c1, c2;
        for(j=0; j<len2; j++){
            c1 = toUpper(str1[i]);
            c2 = toUpper(str2[j]);
            if(c1 == c2)    break;
        }
        //如果找不到这个字符，说明丢失，将其输出
        if(j==len2 && !isPrint[c1]){
            printf("%c", c1);
            isPrint[c1] = true;
        }

    }
    printf("\n");
    return 0;
}

//13:09 AC
