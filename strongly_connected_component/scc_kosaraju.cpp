#include <bits/stdc++.h>
using namespace std;

int N;
stack<int> DFS_TREE;
//SCCNUM[i] = j : i-th node is a component of j-th scc
vector<int> SCCNUM(N, -1);
//SCC[i] = {j, k, l, ...} : j, k, l... are components of i-th scc
vector<vector<int>> SCC;

//original graph
vector<vector<int>> G(N);
vector<bool> VISIT(N, false);

//reversed graph(every edges reversed)
vector<vector<int>> T(N);
vector<bool> RVISIT(N, false);

void dfs(int node){
	if(VISIT[node]) return;
	VISIT[node] = true;

	for(int child : G[node]){
		if(!VISIT[child]){
			dfs(child);
		}
	}

	DFS_TREE.push(child);

	return;
}

void rdfs(int node, int sccnum, vector<int>& scc){
	if(RVISIT[node]) return;
	RVISIT[node] = true;
	SCCNUM[node] = sccnum;
	scc.push_back(node);
	for(int child : T[node]){
		if(!RVISIT[child]){
			rdfs(child, sccnum, scc);
		}
	}
	return;
}

void make_scc(void){
	for(int i = 0; i < N; i++){
		if(!VISIT[i]) dfs(i);
	}

	int scc_num = 0;
	while(DFS_TREE.empty()){
		int node = DFS_TREE.top(); DFS_TREE.pop();

		if(RVISIT[node]){
			continue;
		} else{
			vector<int> temp_scc;
			rdfs(node, scc_num, temp_scc);
			scc_num++;
			SCC.push_back(temp_scc);
		}
	}
	return;
}
