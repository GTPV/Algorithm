#include <bits/stdc++.h>
using namespace std;

class edge{
	public:
		edge(){
			start = 0;
			end = 0;
			weight = 0;
		}
		edge(int s, int e, int w){
			start = s;
			end = e;
			weight = w;
		}

		int start, end, weight;
};

struct cmp{
	bool operator()(edge& lhs, edge& rhs){
		return lhs.weight > rhs.weight;
	}
};

int V, E;

priority_queue<edge, vector<edge>, cmp> EDGES;
vector<edge> MST;

vector<int> PARENT(V, -1);

int get_parent(int node){
	int Temp, Root;
	for(Root = node; PARENT[Root] >= 0; Root = PARENT[Root]);
	while(Root != node){
		Temp = PARENT[node];
		PARENT[node] = Root;
		node = Temp;
	}

	return Root;
}

void merge(int node1, int node2){
	int Parent1 = get_parent(node1);
	int Parent2 = get_parent(node2);

	if(Parent1 > Parent2){
		PARENT[Parent2] += PARENT[Parent1];
		PARENT[Parent1] = Parent2;
	} else{
		PARENT[Parent1] += PARENT[Parent2];
		PARENT[Parent2] = Parent1;
	}

	return;
}

bool build_mst(){
	while(!EDGES.empty()){
		edge Temp = EDGES.top(); EDGES.pop();
		int S = Temp.start;
		int E = Temp.end;
		int W = Temp.weight;
		if(get_parent(S) == get_parent(E)){
			continue;
		} else{
			merge(S, E);
			MST.push_back(Temp);
		}
	}

	if(MST.size() == V-1){
		return true;
	} else{
		return false;
	}
}
