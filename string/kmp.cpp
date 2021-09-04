#include <bits/stdc++.h>
using namespace std;

string TARGET, ORIGIN;

vector<int> get_partial_match2(string S){
	int L = S.size();
	vector<int> pi(L, 0);

	int start = 1, matched = 0;

	while(start + matched < L){
		if(S[start + matched] == S[matched]){
			matched++;
			pi[start+matched - 1] = matched;
		} else{
			if(matched == 0) start++;
			else{
				start += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}

	return pi;
}

vector<int> get_partial_match1(string S){
	int L = S.size();
	vector<int> pi(L, 0);

	int matched = 0;
	for(int i = 1; i < L; i++){
		while(matched > 0 && S[i] != S[matched]){
			matched = pi[matched-1];
		}

		if(S[i] == S[matched]){
			matched++;
			pi[i] = matched;
		}
	}

	return pi;
}

vector<int> kmp_search(string origin, string target){
	vector<int> pi = get_partial_match(target);
	vector<int> Ans;

	int matched = 0;

	for(int i = 0; i < origin.size(); i++){
		while(matched > 0 && origin[i] != target[matched]){
			matched = pi[matched-1];
		}

		if(origin[i] == target[matched]){
			if(matched == target.size()-1){
				Ans.push_back(i - matched + 1);
				matched = pi[matched];
			} else{
				matched++;
			}
		}
	}

	return Ans;
}
