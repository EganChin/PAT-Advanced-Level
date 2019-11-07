//
// Created by Administrator on 2019/8/27.
//

/**
 * Answering at 2019/9/18 10:02
 */

/**
 *
Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3

Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0
 **/

// begin at 07/11/19 15:34 

#include<iostream>
#include<map>
#include<string>
using namespace std;

#define MAX_NUM 2010

map<string, int> gang;
map<string, int> strToInt;
map<int, string> intToStr;

int N, K;

int Graph[MAX_NUM][MAX_NUM] = {0}, weight[MAX_NUM] = {0}, visit[MAX_NUM] = {0}, personNum=0;

int convertToInt(const string &name){
	if(strToInt.find(name) == strToInt.end()){
		strToInt[name] = personNum;
		intToStr[personNum] = name;
		personNum++;
	}
	return strToInt[name]; 
}

void DFS(int u, int &head, int &memberNum, int &totalWeight){
	//if the vertex has visited, skip it, else visit
	if(!visit[u]){
		visit[u] = true;
		//calculate the head of the gang 
		if(weight[u] > weight[head]){
			head = u;
		}
		memberNum++;
		for(int v=0; v<personNum; v++){
			//if u and v has phone record more than one time, then calculate member and total weight
			if(Graph[u][v] > 0){
				totalWeight += Graph[u][v];
				//after caculation, delete the record(be care of the graph is undirected )	
				Graph[u][v] = Graph[v][u] = 0;
				if(!visit[v])
					DFS(v, head, memberNum, totalWeight);
			}
		}
	}
}

void DFSTravel(){
	for(int i=0; i<personNum; i++){
		int head = i, memberNum = 0, totalWeight=0;
		DFS(i, head, memberNum, totalWeight);
		cout << intToStr[head] << "," << head << "," << memberNum << "," << totalWeight << endl;
		if(memberNum > 2 && totalWeight > K){
			gang[intToStr[head]] = memberNum;
		}
	}
}

int main(){
	int time, u, v;
	cin >> N >> K;
	for(int i=0; i<N; i++){
		string name1, name2;
		cin >> name1 >> name2 >> time;
		u = convertToInt(name1), v = convertToInt(name2);
		Graph[u][v] = Graph[v][u] = (Graph[u][v] + time);
		weight[u] += time, weight[v] += time;
	}
	
	
	DFSTravel(); 
	
	cout << gang.size() << endl;
	for(const auto &it : gang){
		cout << it.first << " " << it.second << endl;
	}
	
}

// finish at 07/11/19 16:37








