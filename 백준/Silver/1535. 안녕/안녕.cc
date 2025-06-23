#include <bits/stdc++.h>

using namespace std;

int n;
int l[25], j[25], dp[105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++) cin >> l[i];
	for(int i=0; i<n; i++) cin >> j[i];
	
	for(int i=0; i<n; i++){
		for(int k=100; k>l[i]; k--){
			dp[k] = max(dp[k], dp[k-l[i]]+j[i]);
		}
	}
	cout << dp[100] << "\n";
	
	return 0;
}