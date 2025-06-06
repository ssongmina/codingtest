#include <bits/stdc++.h>

using namespace std;

int n;
string str;
vector<string> v;

bool cmp(string a, string b){
	if(a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	while(n--){
		cin >> str;
		if(find(v.begin(), v.end(), str) != v.end()) continue;
		v.push_back(str);
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(auto a : v) cout << a << "\n";
	
	
	return 0;
}