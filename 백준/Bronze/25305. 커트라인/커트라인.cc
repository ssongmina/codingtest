#include <bits/stdc++.h>

using namespace std;

int x,n,m;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
	}
	
	sort(v.begin(), v.end());
	
	cout << v[n-m] << "\n";
	
	
	return 0;
}