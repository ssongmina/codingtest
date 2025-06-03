#include <bits/stdc++.h>

using namespace std;

char c;
string tmp1, tmp2, str;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> tmp1 >> tmp2;
		
	c = tmp2[tmp2.size()-1];
	for(int i=0; i<tmp1.size(); i++){
		str += tmp1[i];
		if(str.size() >= tmp2.size() && tmp1[i] == c){
			string ss = str.substr(str.size()-tmp2.size());
			if(ss == tmp2) str.erase(str.size()-tmp2.size(), tmp2.size());
		}
	}
	
	if(str.size()) cout << str << "\n";
	else cout << "FRULA\n";
	return 0;
}