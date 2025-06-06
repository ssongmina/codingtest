#include <bits/stdc++.h>

using namespace std;

int n,y,x;
vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	while(n--){
		cin >> y >> x;
		v.push_back({y,x});
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(auto a : v) cout << a.first << " " << a.second << "\n";
	
	
	return 0;
}