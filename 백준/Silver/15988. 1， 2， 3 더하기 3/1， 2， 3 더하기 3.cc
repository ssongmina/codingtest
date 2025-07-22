#include <bits/stdc++.h>

using namespace std;

int t,n;
int dp[1000009];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 1000000; i++) {
        dp[i] = ((long long)dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
    }
	
	for(int i=0; i<t; i++){
		cin >> n;
		cout << dp[n] << "\n";
	}
	
	return 0;
}