/*
1025 PAT Ranking (25)
Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive number N (<=100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

Output Specification:

For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:

registration_number final_rank location_number local_rank

The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

Sample Input:

2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85

Sample Output:

9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
*/
//#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_TESTEE_NUM 100*300+1

struct Testee
{
	char number[14];
	int location;
	int localRank;
	int score;
}testees[MAX_TESTEE_NUM];

int cmp(Testee a, Testee b) {
	if (a.score != b.score)
		return a.score > b.score;
	return strcmp(a.number, b.number) < 0;
}

int main()
{

	int location_num;
	scanf("%d", &location_num);
	int total_num = 0;
	for (int i = 0; i < location_num; i++) {
		int testee_num;
		scanf("%d", &testee_num);
		for (int j = 0; j < testee_num; j++) {
			scanf("%s %d", testees[total_num].number, &testees[total_num].score);
			testees[total_num++].location = i + 1;
		}
		sort(testees + total_num - testee_num, testees + total_num, cmp);

		testees[total_num - testee_num].localRank = 1;


		for (int j = total_num - testee_num + 1; j < total_num; j++) {
			if (testees[j].score == testees[j - 1].score)
				testees[j].localRank = testees[j - 1].localRank;
			else 
				testees[j].localRank = j + 1 - total_num + testee_num;
		}
	}


	sort(testees, testees + total_num, cmp);

	printf("%d\n", total_num);

	int fianl_rank = 1;

	for (int i = 0; i < total_num; i++) {

		if (i != 0 && testees[i].score != testees[i - 1].score)
			fianl_rank = i + 1;

		printf("%s %d %d %d\n", testees[i].number, fianl_rank,
			testees[i].location, testees[i].localRank);
	}

	system("PAUSE");

	return 0;
}
