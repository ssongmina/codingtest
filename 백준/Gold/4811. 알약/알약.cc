#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[34][34];

long long go(int full, int half){
	if(full == 0 && half == 0) return 1;
	long long &ret = dp[full][half];
	if(ret) return ret;
	if(half > 0) ret += go(full, half-1);
	if(full > 0) ret += go(full-1, half+1);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(true){
		cin >> n;
		if(n == 0) break;
		cout << go(n,0) << "\n";
	}
	
	return 0;
}