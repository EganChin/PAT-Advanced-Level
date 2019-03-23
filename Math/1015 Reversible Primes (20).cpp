/*
1015 Reversible Primes （20 分)
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (<10
​5
​​ ) and D (1<D≤10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:
For each test case, print in one line Yes if N is a reversible prime with radix D, or No if not.

Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No
*/

//2019.3.23 13:27 reading
//2019.3.23 13:29 read


#include<iostream>
#include<cmath>
using namespace std;

int radix[100];

bool isPrime(int n){
    //注意判断1
    if(n<=1)
        return false;
    for(int i=2; i<=(int)sqrt(1.0*n); i++)
        if(n%i==0)
            return false;
    return true;
}

int reverse(int n, int d){
    int len = 0;
    //进制转换
    do{
        radix[len++] = n%d;
        n/=d;
    }while(n!=0);
    //逆序
    for(int i=0; i<len; i++)
        n = n*d+radix[i];
    return n;
}

int main(){
    int n, d;

    while( scanf("%d", &n) != EOF){
        if(n<0)
            break;
        scanf("%d", &d);
        if(!isPrime(n)){
            printf("No\n");
        }else{
            if(isPrime(reverse(n, d)))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}

//13:47 AC
