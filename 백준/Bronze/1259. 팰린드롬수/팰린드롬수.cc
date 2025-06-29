#include <bits/stdc++.h>

using namespace std;

string str;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(true){
		cin >> str;
		if(str == "0") break;
		string temp = str;
		reverse(str.begin(), str.end());
		if(temp == str) cout << "yes\n";
		else cout << "no\n";
	}
	
	return 0;
}