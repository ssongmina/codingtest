#include <bits/stdc++.h>

using namespace std;

string s;
vector<int> v(28, 0);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> s;
	for(int i=0; i<s.size(); i++){
		char c = s[i];
		v[s[i] - 'a']++;
	}
	
	for(int i=0; i<26; i++)
		cout << v[i] << " ";
	
}