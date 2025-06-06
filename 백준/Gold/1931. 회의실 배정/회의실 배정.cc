#include <bits/stdc++.h>

using namespace std;

int n,s,e,ret;
vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++){
		cin >> s >> e;
		v.push_back({s,e});
	}
	sort(v.begin(), v.end(), cmp);
	
	ret = 1;
	int idx = 0;
	s = v[0].second;
	for(int i=1; i<n; i++){
		if(s <= v[i].first){
			ret++;
			s = v[i].second;
		}
	}
	cout << ret << "\n";
	
	return 0;
}