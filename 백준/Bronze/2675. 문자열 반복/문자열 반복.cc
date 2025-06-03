#include <bits/stdc++.h>

using namespace std;

int t,n;
string str;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n >> str;
		for(int i=0; i<str.size(); i++){
			for(int j=0; j<n; j++) cout << str[i];
		}
		cout << "\n";
	}
	
	return 0;
}