/*
1095 Cars on Campus （30 分）
Zhejiang University has 8 campuses and a lot of gates.

From each gate we can collect the in/out times and the plate numbers of the cars crossing the gate.

Now with all the information available, you are supposed to tell,

at any specific time point, the number of cars parking on campus,

and at the end of the day find the cars that have parked for the longest time period.

Input Specification:
Each input file contains one test case. Each case starts with two positive integers
    N (≤10^4​​), the number of records,
    and K (≤8×10^4) the number of queries.
Then N lines follow, each gives a record in the format:

    plate_number hh:mm:ss status

where plate_number is a string of 7 English capital letters or 1-digit numbers; hh:mm:ss represents the time point in a day by hour:minute:second,

with the earliest time being 00:00:00 and the latest 23:59:59; and status is either in or out.

Note that all times will be within a single day.

Each in record is paired with the chronologically next record for the same car provided it is an out record.

Any in records that are not paired with an out record are ignored, as are out records not paired with an in record.

It is guaranteed that at least one car is well paired in the input, and no car is both in and out at the same moment.

Times are recorded using a 24-hour clock.

Then K lines of queries follow, each gives a time point in the format hh:mm:ss.

Note: the queries are given in accending order of the times.

Output Specification:
For each query, output in a line the total number of cars parking on campus.

The last line of output is supposed to give the plate number of the car that has parked for the longest time period,

and the corresponding time length. If such a car is not unique, then output all of their plate numbers in a line in alphabetical order,

separated by a space.

Sample Input:
16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00
Sample Output:
1
4
5
2
1
0
1
JH007BD ZD00001 07:20:09
*/

//2018.9.16
//10:35 Reading
//10:48 Read

#include<map>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int max_n = 10010;

struct Car{
    char id[8];
    int second; //当前记录的秒数
    char status[4];
}all[max_n], valid[max_n];

int cmpByIdAndTime(Car a, Car b){
    return strcmp(a.id, b.id) ? strcmp(a.id, b.id) < 0 : a.second < b.second;
}

int cmpByTime(Car a, Car b){
    return a.second < b.second;
}

int toSecond(int hh, int mm, int ss){
    return hh*3600+mm*60+ss;
}

int main(){

    int n, k;
    scanf("%d%d", &n, &k);

    for(int i=0; i<n; i++){
        int hh, mm, ss;
        scanf("%s %d:%d:%d %s", all[i].id, &hh, &mm, &ss, all[i].status);
        all[i].second = toSecond(hh, mm, ss);
    }

    sort(all, all+n, cmpByIdAndTime);

    map<string, int> parkTime;  //所有车辆的停留时间

    int maxTime = -1, vNum = 0;
    //判断记录有效性并计算最大停留时间
    for(int i=1; i<n; i++){
        if(!strcmp(all[i-1].id, all[i].id) && !strcmp(all[i-1].status, "in") && !strcmp(all[i].status, "out")){
            valid[vNum++] = all[i-1];
            valid[vNum++] = all[i];
            if(!parkTime.count(all[i].id))
                parkTime[all[i].id] = 0;
            parkTime[all[i].id] += all[i].second - all[i-1].second;
            maxTime = max(maxTime, parkTime[all[i].id]);
        }
    }

    sort(valid, valid+vNum, cmpByTime);

    int now = 0, cNum = 0;  //当前查询时刻和当前在校车辆数
    for(int i=0; i<k; i++){
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int qTime = toSecond(hh, mm, ss);
        while(now < vNum && valid[now].second <= qTime){
            !strcmp(valid[now++].status, "in") ? cNum++ : cNum--;
        }
        printf("%d\n", cNum);
    }

    map<string, int>::iterator iter;

    //输入停留时间最长的车牌号
    for(iter = parkTime.begin(); iter != parkTime.end(); iter++){
        if(iter->second == maxTime)
            printf("%s ", iter->first.c_str());
    }

    //输出24小时的最长停留时间
    printf("%02d:%02d:%02d\n", maxTime/3600, maxTime%3600/60, maxTime%60);

    return 0;
}

//11:11 PAUSE
//11:52 RESUME
//12:21 TO
//12:24 AC
