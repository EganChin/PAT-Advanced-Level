/*
1010 Radix （25 分）
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true?

The answer is yes, if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.

Input Specification:
Each input file contains one test case. Each case occupies a line which contains 4 positive integers:


N1 N2 tag radix

Here N1 and N2 each has no more than 10 digits. A digit is less than its radix

and is chosen from the set { 0-9, a-z } where 0-9 represent the decimal numbers 0-9,

and a-z represent the decimal numbers 10-35.

The last number radix is the radix of N1 if tag is 1, or of N2 if tag is 2.

Output Specification:
For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true.

If the equation is impossible, print Impossible. If the solution is not unique, output the smallest possible radix.

Sample Input 1:
6 110 1 10
Sample Output 1:
2
Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible
*/

//2018.10.8
//11:18 reading
//11:23 read

//盲区：不能想当然的认为最大进制是36，在进制转换过程中，随时有可能发生溢出

#include<algorithm>
#include<cstdio>
#include<cstring>

long long IntMap[256];

const long long inf = (1LL << 63) - 1;   //long long最大值

void init(){
    for(char ch = '0'; ch <= '9'; ch++)
        IntMap[ch] = ch - '0';
    for(char ch = 'a'; ch <= 'z'; ch++)
        IntMap[ch] = ch -'a'+10;
}

long long convertToDec(char N[], long long radix, long long ub){
    long long ans = 0;
    int len = strlen(N);
    for(int i=0; i<len; i++){
        ans = ans * radix + IntMap[N[i]];
        if(ans > ub) return -1; //超过inf或N1，发生溢出
    }
    return ans;
}

int cmp(char N2[], long long radix, long long N1Dec){
    long long N2Dec = convertToDec(N2, radix, N1Dec);
    if(N2Dec<0 || N2Dec > N1Dec) return 1; //溢出说明N2DEC > N1DEC
    else if(N2Dec == N1Dec)  return 0;   //相等
    else return -1;    //N2Dec < N1Dec
}

long long binarySearch(char N2[], long long left, long long right, long long N1Dec){
    long long mid;
    while(left <= right){
        mid = (left + right)/2;
        int flag = cmp(N2, mid, N1Dec);
        if(!flag) return mid;
        else if(flag == -1)  left = mid + 1;
        else right = mid - 1;
    }

    return -1; //impossible
}

int findLargestDigit(char N2[]){
    int len = strlen(N2), ans = -1;
    for(int i=0; i<len; i++)
        if(ans < IntMap[N2[i]])
            ans = IntMap[N2[i]];
    return ans + 1;
}

int main()
{
    char N1[20], N2[20];
    int tag, radix;

    init();
    scanf("%s %s %d %d", N1, N2, &tag, &radix);
    //方便起见，N1为确认进制的数，N2为未确认进制的数
    if(tag == 2){
        char temp[12];
        strcpy(temp, N1);
        strcpy(N1, N2);
        strcpy(N2, temp);
    }
    long long N1Dec = convertToDec(N1, radix, inf);
    long long low = findLargestDigit(N2);   //  找到N2的最大数位+1作为下界
    long long high = std::max(low, N1Dec);    //上界
    long long ans = binarySearch(N2, low, high, N1Dec);
    ans == -1 ? printf("Impossible\n") : printf("%d\n", ans);

    return 0;
}

//13:24 AC 未通过原因：IntMap[ch] = ch -'0'+10;
