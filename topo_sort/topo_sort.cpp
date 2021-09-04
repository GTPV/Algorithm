#include <bits/stdc++.h>
using namespace std;

int V, E;
//only children are in ADJ[i] (because it's directed graph)
vector<vector<int>> ADJ;
vector<int> SORTED;
vector<int> PARENT(V, 0);

void topo_sort(){
	for(int i = 0; i < V; i++){
		for(auto child : ADJ[i]){
			// (i -> child) edge exists!
			PARENT[child]++;
		}
	}

	queue<int> Q;

	for(int i = 0; i < V; i++){
		if(PARENT[i] == 0){
			Q.push(i);
		}
	}

	while(!Q.empty()){
		int Current = Q.front();
		Q.pop();

		SORTED.push(Current);

		for(auto child : ADJ[Current]){
			PARENT[child]--;
			if(PARENT[child] == 0){
				Q.push(child);
			}
		}
	}
	return;
}
