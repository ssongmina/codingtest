#include <bits/stdc++.h>

using namespace std;

int t;
string str;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> str;
		int cnt = 0, sum = 0;
		for(int i=0; i<str.size(); i++){
			if(str[i] == 'O') cnt++, sum += cnt;
			else cnt = 0;
		}
		cout << sum << "\n";
	}
	
	return 0;
}