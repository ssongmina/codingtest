#include <bits/stdc++.h>

using namespace std;

int t,n;
pair<int,int> dp[45];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	dp[0] = {1,0}, dp[1] = {0,1};
	for(int i=2; i<=40; i++){
		dp[i] = {dp[i-1].first+dp[i-2].first, dp[i-1].second+dp[i-2].second};
	}
	while(t--){
		cin >> n;
		cout << dp[n].first << " " << dp[n].second << "\n";
	}
	
	return 0;
}