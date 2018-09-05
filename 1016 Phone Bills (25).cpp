/*
A long-distance telephone company charges its customers by the following rules:

Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hands up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.

Input Specification:
Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.

The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.

The next line contains a positive number N (â‰¤1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word on-line or off-line.

For each test case, all dates will be within a single month. Each on-line record is paired with the chronologically next record for the same customer provided it is an off-line record. Any on-line records that are not paired with an off-line record are ignored, as are off-line records not paired with an on-line record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.

Output Specification:
For each test case, you must print a phone bill for each customer.

Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.

Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
*/

#include <iostream>
#include <cstring> 
#include <algorithm>
using namespace std;
#define MAX_RECORD_NUM 1010

int toll[24];

typedef struct Record Record;
struct Record{
    char name[25];
    int month, day, hour, minute;
    bool status;
}record[MAX_RECORD_NUM];

int cmp(Record a, Record b){
    int ncmp = strcmp(a.name, b.name);
    if(ncmp != 0)
        return ncmp < 0;
    else if(a.month != b.month)
        return a.month < b.month;
    else if(a.day != b.day)
        return a.day < b.day;
    else if(a.hour != b.hour)
        return a.hour < b.hour;
    return a.minute < b.minute;
}

void generateBill(int on, int off, int &time, int &money){
	Record temp = record[on];
	while(temp.day < record[off].day || temp.hour < record[off].hour || temp.minute < record[off].minute){
		time++;
		money += toll[temp.hour];
		temp.minute++;
		if(temp.minute >= 60){
			temp.minute=0;
			temp.hour++;
		}
		if(temp.hour >= 24){
			temp.hour = 0;
			temp.day++;
		}
	}
}

int main(){
    for(int i=0; i<24; i++){
        scanf("%d", &toll[i]);        
    }
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%s %d:%d:%d:%d", 
        record[i].name, 
        &record[i].month, &record[i].day, &record[i].hour, &record[i].minute);
		
		char status[10];
		scanf("%s", status);
		record[i].status = strcmp(status, "on-line") == 0 ? true : false;   
    }
    
    sort(record, record+N, cmp);
    
	int on = 0, off, next;
	while(on < N){
		//ÊÇ·ñÊä³ö£¬0ÊÇ³õÊ¼×´Ì¬£¬1ÊÇÕÒµ½on£¬2ÊÇÔÚÕÒµ½onºóÕÒµ½off 
		int needPrint = 0;
		next = on;
		while(next < N && !strcmp(record[on].name, record[next].name)){
			if(!needPrint && record[next].status)
				needPrint = 1;
			else if(needPrint == 1 && !record[next].status)
				needPrint = 2;
			next++;
		}
		//Ã»ÓÐÕÒµ½Åä¶ÔµÄon-off£¬¸ÃÓÃ»§ÎÞÓÐÐ§¼ÇÂ¼£¬Ìø¹ý 
		if(needPrint < 2){
			on = next;
			continue;
		}
		int allMoney = 0;
		printf("%s %02d\n", record[on].name, record[on].month);
		while(on < next){
			//Ñ°ÕÒÁ¬ÐøµÄon-lineºÍoff-line 
			while(on < next - 1
				&& !(record[on].status && !record[on+1].status)){
					on++;
				}
				off = on + 1;	//off±ØÐëÔÚonÏÂÃæ
				//¸ÃÓÃ»§µÄËùÓÐ¼ÇÂ¼ÒÑÊä³öÍê±Ï£¬´¦ÀíÏÂÒ»¸öÓÃ»§ 
				if(off == next){
					on = next;
					break;
				} 
				printf("%02d:%02d:%02d %02d:%02d:%02d ",
					record[on].day, record[on].hour, record[on].minute,
					record[off].day, record[off].hour, record[off].minute);
					
				int time=0, money=0;
				
				generateBill(on, off, time, money);
				allMoney += money;
				printf("%d $%.2f\n", time, money/100.0);
				on = off + 1;
		}
		printf("Total amount: $%.2f\n", allMoney/100.0);
	} 
	
	return 0;
}
