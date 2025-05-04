#include <bits/stdc++.h>

using namespace std;

int n;
string s, tmp;
vector<int> v(26,0);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> s;
		v[s[0]-'a']++;
	}
	
	for(int i=0; i<26; i++){
		if(v[i] >= 5) tmp += (char)('a'+i);
	}
	
	if(tmp.size() == 0) cout << "PREDAJA\n";
	else cout << tmp << "\n";
	
	return 0;
}