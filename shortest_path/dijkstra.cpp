#include <bits/stdc++.h>
using namespace std;
#define INF

int V, E;

vector<int> MINCOST(V, INF);
vector<vector<pair<int, int>>> ADJ;

struct cmp{
	bool operator()(pair<int, int>& lhs, pair<int, int>& rhs){
		return lhs.second > rhs.second;
	}
};

void dijkstra(int start){
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> PQ;
	MINCOST[start] = 0;
	PQ.push({start, 0});

	while(!PQ.empty()){
		int Current = PQ.top().first;
		int Dist = PQ.top().second;
		PQ.pop();

		for(auto next : ADJ[Current]){
			int Next = next.first;
			int Cost = next.second + Dist;
			if(MINCOST[Next] > Cost){
				MINCOST[Next] = Cost;
				PQ.push({Next, Cost});
			}
		}
	}

	return;
}
