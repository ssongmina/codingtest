#include <bits/stdc++.h>

using namespace std;

int n;
string s1, s2;
map<string,string> mp;
vector<string> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> s1 >> s2;
		mp[s1] = s2;
	}
	
	for(auto a : mp){
		if(a.second == "enter") v.push_back(a.first);
	}
	
	sort(v.begin(), v.end());
	for(int i=v.size()-1; i>=0; i--){
		cout << v[i] << "\n";
	}
	
	return 0;
}