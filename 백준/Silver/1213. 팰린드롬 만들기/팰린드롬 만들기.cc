#include <bits/stdc++.h>

using namespace std;

string tmp, str, s;
vector<int> v(26,0);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL); 
	
	cin >> tmp;
	for(int i=0; i<tmp.size(); i++){
		char c = tmp[i];
		v[c-'A']++;
	}
	
	for(int i=0; i<26; i++){
		for(int j=0; j<v[i]/2; j++) str += (char)('A'+i);
		if(v[i] % 2 != 0) 	
			s += (char)('A'+i);
	}
	
	if(s.size() > 1) cout << "I'm Sorry Hansoo\n";
	else{
		cout << str;
		reverse(str.begin(), str.end());
		cout << s;
		cout << str << "\n";
	}
	
	return 0;
}