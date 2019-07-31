//
// Created by Administrator on 2019/7/29.
//
/**
 * People on Mars count their numbers with base 13:

Zero on Earth is called "tret" on Mars.
The numbers 1 to 12 on Earth is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars, respectively.
For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.
For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov" on Mars corresponds to 115 on Earth. In order to help communication between people from these two planets, you are supposed to write a program for mutual translation between Earth and Mars number systems.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<100). Then N lines follow, each contains a number in [0, 169), given either in the form of an Earth number, or that of Mars.

Output Specification:
For each number, print in a line the corresponding number in the other language.

Sample Input:
4
29
5
elo nov
tam
Sample Output:
hel mar
may
115
13
 * **/

//2019.7.31 read

#include <iostream>
#include <map>
#include <string>
#include <cstring>

using namespace std;

int main() {
    string lower[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};

    string higher[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

    string earthToMar[170];
    map<string, int> marToEarth;


    for (int i = 0; i < 13; i++) {
        earthToMar[i] = lower[i];
        marToEarth[lower[i]] = i;
        //建立高12位的语言映射
        earthToMar[(i) * 13] = higher[i];
        marToEarth[higher[i]] = (i) * 13;
    }

    for (int h = 1; h < 13; h++) {
        for (int l = 1; l < 13; l++) {
            string str = higher[h] + " " + lower[l];
            earthToMar[h * 13 + l] = str;
            marToEarth[str] = h * 13 + l;
        }
    }

    int n;
    scanf("%d%*c", &n);

    while (n--) {
        string str, mar;
        getline(cin, str);
        if (str[0] >= '0' && str[0] <= '9') {
            //转数字
            int num = 0;
            for (char i : str)
                num = num * 10 + (i - '0');
            cout << earthToMar[num] << endl;
        } else {
            cout << marToEarth[str] << endl;
        }
    }
}

//17:57 PAT AC