#include <bits/stdc++.h>

using namespace std;

int n,m,x;
vector<int> v;
set<vector<int>> s;

void go(int idx, vector<int> vv){
	if(vv.size() == m){
		s.insert(vv);
		return ;
	}
	for(int i=idx; i<n; i++){
		vv.push_back(v[i]);
		go(i, vv);
		vv.pop_back();
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	
	vector<int> vv;
	go(0,vv);
	
	for(auto a : s){
		for(auto aa : a){
			cout << aa << " ";
		}
		cout << "\n";
	}
	
	return 0;
}