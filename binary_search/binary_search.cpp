#include <bits/stdc++.h>
using namespace std;

int N;

//ARR should be sorted
vector<int> ARR;

int upper_bound(int start, int end, int target){
	/*
	   finding upper bound of 'target'
	   in interval [ ARR[start], ARR[end] ]

	   upper bound : first index such that ARR[i] > target;
	*/

	while(start < end){
		int mid = (start + end) / 2;

		if(ARR[mid] < target){
			start = mid + 1;
		} else if(ARR[mid] == target){
			start = mid + 1;
		} else{
			end = mid;
		}
	}

	return start;
}

int lower_bound(int start, int end, int target){
	/*
	   finding lower bound of 'target'
	   in interval [ARR[start], ARR[end]]

	   lower bound : first index such that ARR[i] >= target
	*/

	while(start < end){
		int mid = (start + end) / 2;

		if(ARR[mid] < target){
			start = mid + 1;
		} else if(ARR[mid] == target){
			end = mid;
		} else{
			end = mid;
		}
	}

	return start;
}

bool binary_search(int start, int end, int target){
	/*
	   finding whether target is in interval [ARR[start], ARR[end]]
	*/

	int lower = lower_bound(start, end, target);
	int upper = upper_bound(start, end, target);

	return !(lower==upper);
}
