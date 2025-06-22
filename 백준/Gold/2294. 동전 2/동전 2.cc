#include <bits/stdc++.h>

using namespace std;

int n,k,x;
vector<int> v;
int dp[10005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
	}
	fill(dp, dp+10005, 1e9);
	
	dp[0] = 0;
	for(auto a : v){
		for(int i=a; i<k+1; i++){
			if(i-a < 0) continue;
			dp[i] = min(dp[i], dp[i-a]+1);
		}
	}
	
	if(dp[k] == 1e9) cout << "-1\n";
	else cout << dp[k] << "\n";
	
	
	return 0;
}