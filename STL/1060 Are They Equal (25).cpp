//
// Created by Administrator on 2019/7/29.
//

/**
 If a machine can save only 3 significant digits, the float numbers 12300 and 12358.9 are considered equal since they are both saved as 0.123×10
​5
​​  with simple chopping. Now given the number of significant digits on a machine and two float numbers, you are supposed to tell if they are treated equal in that machine.

Input Specification:
Each input file contains one test case which gives three numbers N, A and B, where N (<100) is the number of significant digits, and A and B are the two float numbers to be compared. Each float number is non-negative, no greater than 10
​100
​​ , and that its total digit number is less than 100.

Output Specification:
For each test case, print in a line YES if the two numbers are treated equal, and then the number in the standard form 0.d[1]...d[N]*10^k (d[1]>0 unless the number is 0); or NO if they are not treated equal, and then the two numbers in their standard form. All the terms must be separated by a space, with no extra space at the end of a line.

Note: Simple chopping is assumed without rounding.

Sample Input 1:
3 12300 12358.9
Sample Output 1:
YES 0.123*10^5
Sample Input 2:

Sample Output 2:
NO 0.120*10^3 0.128*10^3
**/

//2019.7.30 16:57 reading
//2019.7.30 17:00 read

#include <iostream>
#include <string>

using namespace std;

int n;

string deal(string s, int &exp) {
    int digit = 0;
    //去掉小数点前的前导零
    while (s.length() > 0 && s[0] == '0')
        s.erase(s.begin());
    //去掉小数点后的前导零
    if (s[0] == '.') {
        s.erase(s.begin());
        while (s.length() > 0 && s[0] == '0') {
            s.erase(s.begin());
            exp--;
        }
    } else {
        //寻找小数点
        while (digit < s.length() && s[digit] != '.') {
            exp++;
            digit++;
        }
        //如果遇到小数点，将其删除
        if (digit < s.length())
            s.erase(s.begin() + digit);
    }
    //如果去掉小数点和其前后的前导零后长度为零，说明等于0
    if (s.length() == 0)
        exp = 0;

    string result;
    result = "0." + result;
    for (int i = 0, j = 0; i < n; i++) {
        if (i < s.length()) result += s[j++];
            //补零
        else result += "0";
    }
    return result;
}

int main() {
    string a, b;
    cin >> n >> a >> b;

    int exp1, exp2;
    a = deal(a, exp1) +"*10^"+exp1;
    b = deal(b, exp2);

    if (a == b && exp1==exp2)
        cout << "YES " << a + "*10^" << exp1 << endl;
    else
        cout << "NO " << a + "*10^" << exp1 << " " << b + "*10^" << exp2 << endl;
//    printf("%s,%s\n", a.c_str(), b.c_str());
}

//7:31 9:09 NC AC
//7:31 9:13 PAT AC(exp1&exp2 uninitialized)