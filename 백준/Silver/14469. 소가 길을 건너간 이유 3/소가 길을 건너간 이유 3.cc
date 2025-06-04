#include <bits/stdc++.h>

using namespace std;

int n,a,b;
vector<pair<int,int>> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a >> b;
		v.push_back({a,b});
	}
	sort(v.begin(), v.end());
	
	int t = 0;
	for(auto a : v){
		if(t < a.first) t = a.first;
		t += a.second;
	}
	cout << t << "\n";
	
	return 0;
}