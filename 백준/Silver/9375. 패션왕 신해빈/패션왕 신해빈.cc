#include <bits/stdc++.h>

using namespace std;

int t, n;
string s, ss;


int main(){
	
	cin >> t;
	while(t--){
		cin >> n;
		map<string, int> mp;
		for(int i=0; i<n; i++){
			cin >> s >> ss;
			mp[ss]++;
		}
		int cnt = 1;
		for(map<string,int>::iterator it = mp.begin(); it != mp.end(); it++){
			cnt *= (it->second + 1);
		}
		cout << cnt-1 << "\n";
	}
	
	return 0;
}