#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<vector<int>> ADJ;
vector<bool> VISIT;

int bfs(int start, int dest){
	queue<int> Q;
	int Ans = 0, Count = 0, Segment = 0;
	bool If_Check = false;

	Q.push(start);
	Segment++;

	while(!Q.empty()){
		Count = 0;
		If_Check = false;

		for(int i = 0; i < Segment; i++){
			int Current = Q.front(); Q.pop();

			if(Current == dest){
				return Ans;
			}

			VISIT[Current] = true;

			for(auto child : ADJ[Current]){
				if(VISIT[child] == false){
					Q.push(child);
					Count++;
					If_Check = true;
				}
			}
		}

		if(If_Check) Ans++;
		Segment = Count;
	}

	return -1;
}
