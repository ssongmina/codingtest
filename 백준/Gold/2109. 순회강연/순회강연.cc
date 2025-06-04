#include <bits/stdc++.h>

using namespace std;

int n,p,d;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> p >> d;
		v.push_back({d,p});
	}
	sort(v.begin(), v.end());
	
	for(auto a : v){
		pq.push(a.second);
		if(pq.size() > a.first) pq.pop();
	}
	
	int cnt = 0;
	while(pq.size()){
		cnt += pq.top();
		pq.pop();
	}
	cout << cnt << '\n';
	
	return 0;
}