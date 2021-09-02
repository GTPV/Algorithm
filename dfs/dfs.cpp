#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ADJ;
vector<bool> VISIT;

void dfs(int node){
	if(VISIT[node]) return;

	VISIT[node] = true;

	for(auto next : ADJ[node]){
		if(VISIT[next] == false){
			dfs(next);
		}
	}

	return;
}
