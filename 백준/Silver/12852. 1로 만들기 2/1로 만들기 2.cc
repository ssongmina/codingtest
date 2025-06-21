#include <bits/stdc++.h>

using namespace std;

#define prev aaaa

int n, dp[1000006], prev[1000006];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=2; i<=n; i++){
		dp[i] = dp[i-1]+1;
		prev[i] = i-1;
		if(i % 2 == 0){
			if(dp[i] > dp[i/2]+1){
				prev[i] = i/2;
				dp[i] = dp[i/2]+1;
			}
		}
		if(i % 3 == 0){
			if(dp[i] > dp[i/3]+1){
				prev[i] = i/3;
				dp[i] = dp[i/3]+1;
			}
		}
	}
	
	cout << dp[n] << "\n";
	for(int i=n; i != 1; i = prev[i]){
		cout << i << " ";
	}
	cout << 1 << "\n";
	
	return 0;
}