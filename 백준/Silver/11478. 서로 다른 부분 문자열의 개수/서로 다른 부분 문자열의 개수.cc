#include <bits/stdc++.h>

using namespace std;

string str;
set<string> s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> str;
	for(int i=0; i<str.size(); i++){
		string tmp = "";
		for(int j=i; j<str.size(); j++){
			tmp += str[j];
			s.insert(tmp);
		}
	}
	cout << s.size() << "\n";

	return 0;
}