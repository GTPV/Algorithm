#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<int> PARENT(V, -1);

//recursive, PARENT[root] = root;
int get_parent(int node){
	if(node == PARENT[node]) return node;
	else return PARENT[node] = get_parent(PARENT[node]);
}

//for+while, PARENT[root] = 0 - sizeof(root-subtree);
int get_parent(int node){
	int temp, root;
	for(root = node; PARENT[root] >= 0; root = PARENT[root]);
	while(node != root){
		temp = PARENT[node];
		PARENT[node] = root;
		node = temp;
	}

	return root;
}

void merge(int node1, int node2){
	int parent1 = get_parent(node1);
	int parent2 = get_parent(node2);

	if(parent1 == parent2) return;
	if(PARENT[parent1] < PARENT[parent2]){
		PARENT[parent1] += PARENT[parent2];
		PARENT[parent2] = parent1;
	} else{
		PAERNT[parent2] += PARENT[parent1];
		PARENT[parent1] = parent2;
	}

	return;
}
