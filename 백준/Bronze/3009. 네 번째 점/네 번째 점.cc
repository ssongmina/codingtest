#include <bits/stdc++.h>

using namespace std;

int y,x;
vector<pair<int,int>> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i=0; i<3; i++){
		cin >> y >> x;
		v.push_back({y,x});
	}
	
	sort(v.begin(), v.end());
	
	int ny,nx;
	if(v[0].first == v[1].first && v[1].first != v[2].first) ny = v[2].first;
	else if(v[2].first == v[1].first && v[1].first != v[0].first) ny = v[0].first;
	else if(v[2].first == v[0].first && v[1].first != v[0].first) ny = v[1].first;
	
	if(v[0].second == v[1].second && v[1].second != v[2].second) nx = v[2].second;
	else if(v[2].second == v[1].second && v[1].second != v[0].second) nx = v[0].second;
	else if(v[2].second == v[0].second && v[1].second != v[0].second) nx = v[1].second;
	
	cout << ny << " " << nx << "\n";
	
	return 0;
}