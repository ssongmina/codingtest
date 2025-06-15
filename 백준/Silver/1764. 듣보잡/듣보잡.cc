#include <bits/stdc++.h>

using namespace std;

int n,m;
string str;
map<string,int> mp;
vector<string> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> str;
		mp[str]++;	
	}
	
	for(int i=0; i<m; i++){
		cin >> str;
		mp[str]++;
		if(mp[str] >= 2) v.push_back(str);
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for(auto a : v) cout << a << "\n";

	return 0;
}