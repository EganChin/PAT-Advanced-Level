/*
1023 Have Fun with Numbers （20 分)
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

Input Specification:
Each input contains one test case. Each case contains one positive integer with no more than 20 digits.

Output Specification:
For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.

Sample Input:
1234567899
Sample Output:
Yes
2469135798
*/

//2019.4.17 14:34 reading
//2019.4.17 14:38 read

#include<iostream>
#include<cstring>
using namespace std;

struct bign{
    int d[21];
    int len;
    bign(){
        memset(d,0,sizeof(d));
        len = 0;
    }
};

bign charge(char str[]){
    bign n;
    n.len = strlen(str);
    for(int i=0; i<n.len; i++)
        n.d[i] = str[n.len - i - 1] - '0';
    return n;
}

bign multi(bign a, int b){
    bign c;
    int carry = 0;
    for(int i=0; i<a.len; i++){
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp%10;
        carry = temp/10;
    }
    while(carry!=0){
        c.d[c.len++] = carry%10;
        carry /= 10;
    }
    return c;
}

bool judge(bign a, bign b){
    if(a.len != b.len)
        return false;
    int count[10] = {0};
    for(int i=0; i<a.len; i++){
        count[a.d[i]]++;
        count[b.d[i]]--;
    }
    for(int i=0; i<10; i++)
        if(count[i])
            return false;
    return true;
}

void print(bign a){
    for(int i=a.len-1; i>=0; i--){
        cout << a.d[i];
    }
    cout << endl;
}

int main(){
    char n[20];
    cin >> n;
    bign a = charge(n);
    bign b = multi(a, 2);
    if(judge(a, b))
        cout << "Yes\n";
    else
        cout << "No\n";
    print(b);
    return 0;
}

//14:58 AC
