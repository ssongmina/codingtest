#include <bits/stdc++.h>

using namespace std;

int n,x;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
	}
	
	sort(v.begin(), v.end());
	
	for(auto a : v) cout << a << "\n";
	return 0;
}