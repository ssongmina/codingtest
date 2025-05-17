#include <bits/stdc++.h>

using namespace std;

int n,m,mn=987654321;
int arr[55][55];
vector<vector<int>> ret;
vector<pair<int,int>> house, chicken;

void combi(int idx, vector<int> v){
	if(v.size() == m){
		ret.push_back(v);
		return ;
	}
	for(int i=idx+1; i<chicken.size(); i++){
		v.push_back(i);
		combi(i,v);
		v.pop_back();
	}
	return ;
}

int check(int idx){
	int rett = 0;
	for(int i=0; i<house.size(); i++){
		int cnt = 987654321;
		int y,x;
		tie(y,x) = house[i];
		for(int j=0; j<ret[idx].size(); j++){
			int y1 = chicken[ret[idx][j]].first;
			int x1 = chicken[ret[idx][j]].second;
			cnt = min(cnt, abs(y1 - y) + abs(x1 - x));
		}
		rett += cnt;
	}
	return rett;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 1) house.push_back({i,j});
			if(arr[i][j] == 2) chicken.push_back({i,j});
		}
	}
	
	vector<int> v;
	combi(-1, v);
	
	for(int i=0; i<ret.size(); i++){
		mn = min(check(i), mn);
	}
	cout << mn << "\n";
	
	return 0;
}