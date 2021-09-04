#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<vector<int>> MAP(V, vector<int>(V));

void floid_warshall(){
	for(int i = 0; i < V; i++){
		MAP[i][i] = 0;
	}

	for(int m = 0; m < V; m++){
		for(int s = 0; s < V; s++){
			for(int e = 0; e < V; e++){
				MAP[s][e] = min(MAP[s][e], MAP[s][m] + MAP[m][e]);
			}
		}
	}

	return;
}
