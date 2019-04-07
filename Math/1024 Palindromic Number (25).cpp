/*
1024 Palindromic Number （25 分)
A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.

Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.

Input Specification:
Each input file contains one test case. Each case consists of two positive numbers N and K, where N (≤10
​10
​​ ) is the initial numer and K (≤100) is the maximum number of steps. The numbers are separated by a space.

Output Specification:
For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.

Sample Input 1:
67 3
Sample Output 1:
484
2
Sample Input 2:
69 3
Sample Output 2:
1353
3
*/

//2019.4.7 15:02 reading
//2019.4.7 15:07 read

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct bign{
    int d[1000];
    int len;
    bign(){
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign change(char str[]){
    bign a;
    a.len = strlen(str);
    for(int i=0; i<a.len; i++)
        a.d[i] = str[a.len-i-1] - '0';
    return a;
}

bign add(bign a, bign b){
    bign c;
    int carry = 0;
    for(int i=0; i<a.len||i<b.len; i++){
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp/10;
    }
    if(carry)
        c.d[c.len++] = carry;
    return c;
}

bool judge(bign a){
    for(int i=0; i<=a.len/2; i++)
        if(a.d[i] != a.d[a.len-i-1])
            return false;
    return true;
}

void print(bign a){
    for(int i=a.len-1; i>=0; i--)
        cout << a.d[i];
    cout << endl;
}

int main(){
    char str[1000];
    int k, t=0;
    cin >> str >> k;
    bign a = change(str);
    while(t<k && !judge(a)){
        bign b = a;
        reverse(b.d, b.d+b.len);
        a = add(a,b);
        t++;
    }
    print(a);
    cout << t << endl;
    return 0;
}

//15:28 AC
