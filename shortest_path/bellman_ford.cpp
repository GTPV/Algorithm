#include <bits/stdc++.h>
using namespace std;

int V, E;

class edge{
	public:
		int start;
		int end;
		int weight;
};

vector<edge> EDGES;
vector<int> MINCOST(V, INF);

bool bellman_ford(int start){
	MINCOST[start] = 0;

	for(int i = 0; i < V-1; i++){
		for(auto Edge : EDGES){
			int S = Edge.start;
			int E = Edge.end;
			int W = Edge.weight;

			if(MINCOST[E] > MINCOST[S] + W){
				MINCOST[E] = MINCOST[S] + W;
			}
		}
	}


	for(auto Edge : EDGES){
		int S = Edge.start;
		int E = Edge.end;
		int W = Edge.weight;

		if(MINCOST[E] > MINCOST[S] + W){
			return false;
		}
	}

	return true;
}
