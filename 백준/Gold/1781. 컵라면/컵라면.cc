#include <bits/stdc++.h>

using namespace std;

int n,a,b;
vector<pair<int,int>> v;

priority_queue<int, vector<int>, greater<int>> pq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a >> b;
		v.push_back({a,b});
	}
	
	sort(v.begin(), v.end());
	
	for(auto a : v){
		pq.push(a.second);
		if(a.first < pq.size()) pq.pop();
	}
	
	int sum = 0;
	while(pq.size()){
		sum += pq.top();
		pq.pop();
	}
	
	cout << sum << "\n";
	
	
	return 0;
}