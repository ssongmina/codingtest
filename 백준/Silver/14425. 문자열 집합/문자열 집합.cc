#include <bits/stdc++.h>

using namespace std;

int n,m,cnt;
string str;
set<string> s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> str;
		s.insert(str);
	}
	for(int i=0; i<m; i++){
		cin >> str;
		if(s.find(str) != s.end()) cnt++;
	}
	
	cout << cnt << "\n";
	
	return 0;
}