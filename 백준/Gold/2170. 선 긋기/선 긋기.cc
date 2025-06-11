#include <bits/stdc++.h>

using namespace std;

int n;
long long x,y;
vector<pair<long long, long long>> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x >> y;
		v.push_back({x,y});
	}
	
	sort(v.begin(), v.end());

	long long last = -1000000005;
	long long cnt = 0;
	for(auto a : v){
		if(last <= a.first) cnt += a.second - a.first;
		else if(a.second > last) cnt += a.second - last;
		last = max(last, a.second);
	}
	
	cout << cnt << "\n";
	
	return 0;
}