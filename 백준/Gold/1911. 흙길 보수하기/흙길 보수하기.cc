#include <bits/stdc++.h>
using namespace std;

long long n, l, s, e;
vector<pair<long long, long long>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> l;
	for(int i = 0; i < n; i++) {
		cin >> s >> e;
		v.push_back({s, e});
	}
	
	sort(v.begin(), v.end());
	
	long long last = 0;
	long long cnt = 0;
	
	for(auto a : v){
		if(last >= a.second) continue;
		if(last < a.first) last = a.first;
		
		long long len = a.second - last;
		long long need = (len + l - 1) / l;
		cnt += need;
		last += need * l;
	}
	
	cout << cnt << "\n";
	return 0;
}
