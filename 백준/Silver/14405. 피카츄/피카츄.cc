#include <bits/stdc++.h>

using namespace std;

bool flag=true;
string str;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> str;
	for(int i=0; i<str.size(); ){
		if(i+1 < str.size() && str.substr(i,2) == "pi"){
			i += 2;
		}
		else if(i+1 < str.size() && str.substr(i,2) == "ka"){
			i += 2;
		}
		else if(i+2 < str.size() && str.substr(i,3) == "chu"){
			i += 3;
		}
		else{
			flag = false;
			break;
		}
	}
	
	if(flag) cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}