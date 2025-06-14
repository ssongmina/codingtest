#include <bits/stdc++.h>

using namespace std;

int n,m,x;
map<int,int> mp;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> x;
		mp[x]++;
	}
	for(int j=0; j<m; j++){
		cin >> x;
		mp[x]++;
	}
	
	int tmp = 0;
	for(auto a : mp){
		if(a.second == 1) tmp++;
	}
	cout << tmp << "\n";
	
	
	return 0;
}