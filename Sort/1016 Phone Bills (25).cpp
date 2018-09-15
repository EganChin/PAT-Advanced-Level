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
		//是否输出，0是初始状态，1是找到on，2是在找到on后找到off
		int needPrint = 0;
		next = on;
		while(next < N && !strcmp(record[on].name, record[next].name)){
			if(!needPrint && record[next].status)
				needPrint = 1;
			else if(needPrint == 1 && !record[next].status)
				needPrint = 2;
			next++;
		}
		//没有找到配对的on-off，该用户无有效记录，跳过
		if(needPrint < 2){
			on = next;
			continue;
		}
		int allMoney = 0;
		printf("%s %02d\n", record[on].name, record[on].month);
		while(on < next){
			//寻找连续的on-line和off-line
			while(on < next - 1
				&& !(record[on].status && !record[on+1].status)){
					on++;
				}
				off = on + 1;	//off必须在on下面
				//该用户的所有记录已输出完毕，处理下一个用户
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
