#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[10], visited[10];
set<vector<int>> s;

void go(vector<int> v){
	if(v.size() == m){
		s.insert(v);
		return ;
	}
	for(int i=0; i<n; i++){
		if(visited[i]) continue;
		v.push_back(arr[i]);
		visited[i] = 1;
		go(v);
		visited[i] = 0;
		v.pop_back();
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	vector<int> v;
	go(v);
	for(auto a : s){
		for(auto aa : a) cout << aa << " ";
		cout << "\n"; 
	}
	
	return 0;
}