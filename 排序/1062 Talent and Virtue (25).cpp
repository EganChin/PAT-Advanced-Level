/*
About 900 years ago, a Chinese philosopher Sima Guang wrote a history book in which he talked about people's talent and virtue. According to his theory, a man being outstanding in both talent and virtue must be a "sage（圣人）"; being less excellent but with one's virtue outweighs talent can be called a "nobleman（君子）"; being good in neither is a "fool man（愚人）"; yet a fool man is better than a "small man（小人）" who prefers talent than virtue.

Now given the grades of talent and virtue of a group of people, you are supposed to rank them according to Sima Guang's theory.

Input Specification:

Each input file contains one test case. Each case first gives 3 positive integers in a line: N (<=10^5^), the total number of people to be ranked; L (>=60), the lower bound of the qualified grades -- that is, only the ones whose grades of talent and virtue are both not below this line will be ranked; and H (<100), the higher line of qualification -- that is, those with both grades not below this line are considered as the "sages", and will be ranked in non-increasing order according to their total grades. Those with talent grades below H but virtue grades not are cosidered as the "noblemen", and are also ranked in non-increasing order according to their total grades, but they are listed after the "sages". Those with both grades below H, but with virtue not lower than talent are considered as the "fool men". They are ranked in the same way but after the "noblemen". The rest of people whose grades both pass the L line are ranked after the "fool men".

Then N lines follow, each gives the information of a person in the format:

ID_Number Virtue_Grade Talent_Grade
where ID_Number is an 8-digit number, and both grades are integers in [0, 100]. All the numbers are separated by a space.

Output Specification:

The first line of output must give M (<=N), the total number of people that are actually ranked. Then M lines follow, each gives the information of a person in the same format as the input, according to the ranking rules. If there is a tie of the total grade, they must be ranked with respect to their virtue grades in non-increasing order. If there is still a tie, then output in increasing order of their ID's.

Sample Input:

14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
Sample Output:

12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
*/

//2018.7.25 17:30

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;      

typedef struct {
    char id[10];
    int virtue;
    int talent;
    int total;
}Person;

int cmp(Person a, Person b)
{
    if(a.total != b.total)
        return a.total > b.total;
    else if(a.virtue != b.virtue)
        return a.virtue > b.virtue;
    else
        return strcmp(a.id, b.id) < 0;
}

void Print(vector<Person> persons)
{
    for(vector<Person>::iterator it = persons.begin(); it!=persons.end(); it++)
        printf("%s %d %d\n", (*it).id, (*it).virtue, (*it).talent);
}

int main()
{
    int N, L, H;
    scanf("%d%d%d", &N, &L, &H);
    vector<Person>sages, noblemen, foolmen, smallmen;
    while(N--){
        Person temp;
        scanf("%s %d %d", temp.id, &temp.virtue, &temp.talent);
        temp.total = temp.virtue + temp.talent;
        if(temp.virtue < L || temp.talent < L)
            continue;
        if(temp.virtue >= H && temp.talent >= H)
            sages.push_back(temp);
        else if(temp.virtue >= H && temp.talent < H)
            noblemen.push_back(temp);
        else if(temp.virtue >= temp.talent)
            foolmen.push_back(temp);
        else
            smallmen.push_back(temp);
    }

    sort(sages.begin(), sages.end(), cmp);
    sort(noblemen.begin(), noblemen.end(), cmp);
    sort(foolmen.begin(), foolmen.end(), cmp);
    sort(smallmen.begin(), smallmen.end(),cmp);

    printf("%d\n", sages.size()+noblemen.size()+foolmen.size()+smallmen.size());

    Print(sages);
    Print(noblemen);
    Print(foolmen);
    Print(smallmen);

    system("PAUSE");
    
    return 0;
}

//2018.7.25 18:10