#include <bits/stdc++.h>
using namespace std;

int Root;
vector<vector<int>> TREE;
vector<int> PARENT;
//initialized -1
vector<int> DEPTH;

void dfs(int node, int depth){
	if(DEPTH[node] >= 0) return;

	DEPTH[node] = depth;

	for(int child : TREE[node]){
		if(DEPTH[child] == -1){
			dfs(child, depth+1);
		}
	}
	return;
}

void make_depth(int root){
	dfs(root, 0);
}

int find_lca(int node1, int node2){
	if(DEPTH[node1] > DEPTH[node2]){
		swap(node1, node2);
	}

	while(DEPTH[node1] != DEPTH[node2]){
		node2 = PARENT[node2];
	}

	while(node1 != node2){
		node1 = PARENT[node1];
		node2 = PARENT[node2];
	}

	return node1;
}

int lca(int node1, int node2){
	make_depth(Root);
	int LCA = find_lca(node1, node2);
	return LCA;
}
