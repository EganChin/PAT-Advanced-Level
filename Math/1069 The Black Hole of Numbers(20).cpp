/*
1069 The Black Hole of Numbers （20 分)
For any 4-digit integer except the ones with all the digits being the same, if we sort the digits in non-increasing order first, and then in non-decreasing order, a new number can be obtained by taking the second number from the first one. Repeat in this manner we will soon end up at the number 6174 -- the black hole of 4-digit numbers. This number is named Kaprekar Constant.

For example, start from 6767, we'll get:

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...
Given any 4-digit number, you are supposed to illustrate the way it gets into the black hole.

Input Specification:
Each input file contains one test case which gives a positive integer N in the range (0,10
​4
​​ ).

Output Specification:
If all the 4 digits of N are the same, print in one line the equation N - N = 0000. Else print each step of calculation in a line until 6174 comes out as the difference. All the numbers must be printed as 4-digit numbers.

Sample Input 1:
6767
Sample Output 1:
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
Sample Input 2:
2222
Sample Output 2:
2222 - 2222 = 0000
*/

//2019.3.19 22:18

#include<iostream>
#include<algorithm>
using namespace std;

const int size = 4;

int cmp(int a, int b){
    return a>b;
}

void toArray(int number, int num[]){
    for(int i=0; i<size;i++){
        num[i] = number%10;
        number /= 10;
    }
}

int toNumber(int num[]){
    int number = 0;
    for(int i=0; i<size; i++)
        number = number*10 + num[i];
    return number;
}

int main()
{
    int number, number1, number2, num1[size], num2[size];
    scanf("%d", &number);
    while(true){
        toArray(number, num1);
        toArray(number, num2);
        sort(num1,num1+size, cmp);
        sort(num2,num2+size);
        number1 = toNumber(num1);
        number2 = toNumber(num2);
        number = number1 - number2;
        printf("%04d - %04d = %04d\n", number1, number2, number);
        if(number == 0 || number == 6174)
            break;
    }
    return 0;
}

//22:40 AC