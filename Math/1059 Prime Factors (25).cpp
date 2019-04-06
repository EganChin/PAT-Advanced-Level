/*
1059 Prime Factors （25 分)
Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p
​1
​​
​k
​1
​​
​​ ×p
​2
​​
​k
​2
​​
​​ ×⋯×p
​m
​​
​k
​ms
​​
​​ .

Input Specification:
Each input file contains one test case which gives a positive integer N in the range of long int.

Output Specification:
Factor N in the format N = p
​1
​​ ^k
​1
​​ *p
​2
​​ ^k
​2
​​ *…*p
​m
​​ ^k
​m
​​ , where p
​i
​​ 's are prime factors of N in increasing order, and the exponent k
​i
​​  is the number of p
​i
​​  -- hence when there is only one p
​i
​​ , k
​i
​​  is 1 and must NOT be printed out.

Sample Input:
97532468
Sample Output:
97532468=2^2*11*17*101*1291
*/

//2019.4.16 14:28 reading
//2019.4.16 14:31 read

#include<iostream>
#include<cmath>
using namespace std;

#define MAX_N 200010

typedef long long LL;

struct factor{
    LL x, cnt;
}factor[10];

LL prime[MAX_N], pNum=0;

bool isPrime(int x){
    if(x==1)
        return false;
    for(LL i=2; i<=(LL)sqrt(x*1.0); i++)
        if(x%i==0)
            return false;
    return true;
}

void findPrimes(){
    for(LL i=1; i<MAX_N; i++)
        if(isPrime(i))
            prime[pNum++] = i;
}

int main(){
    findPrimes();
    LL n, m, num = 0;
    scanf("%d", &n);
    m = n;
    for(LL i=0; i<pNum; i++){
        if(n%prime[i] == 0){
            factor[num].x = prime[i];
            factor[num].cnt = 0;
            while(n%prime[i] == 0){
                factor[num].cnt++;
                n/=factor[num].x;
            }
            num++;
        }
        if(n==1) break;
    }

    if(n!=1){
        factor[num].x = n;
        factor[num++].cnt = 0;
    }
    printf("%lld=", m);
    if(num==0)
        printf("%lld", m);
    for(LL i=0; i<num; i++){
        printf("%lld", factor[i].x);
        if(factor[i].cnt>1)
            printf("^%lld", factor[i].cnt);
        if(i!=num-1)
            printf("*");
    }

    printf("\n");
}

//14:53 PTA AC
//15:14 NOWCODER AC
