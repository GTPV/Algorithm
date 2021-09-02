#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<vector<int>> ADJ;
vector<int> VISIT;

void bfs(int start){
	queue<int> Q;

	Q.push(start);
	VISIT[start] = true;

	while(!Q.empty()){
		int Current = Q.front(); Q.pop();
		VISIT[Current] = true;

		for(auto Next : ADJ[Current]){
			if(VISIT[Next] == false){
				Q.push(Next);
			}
		}
	}
	return;
}
