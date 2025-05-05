#include <bits/stdc++.h>

using namespace std;

int n,m,x;
string str;
map<string, int> mp1;
map<int, string> mp2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> str;
		mp1[str] = i;
		mp2[i] = str;
	}
	for(int i=1; i<=m; i++){
		cin >> str;
		if((x = atoi(str.c_str())) == 0){  // 문자이다 
			cout << mp1[str] << "\n"; 
		} else cout << mp2[x] << "\n";
	}
	
	return 0;
}