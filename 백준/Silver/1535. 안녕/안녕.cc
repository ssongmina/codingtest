#include <bits/stdc++.h>

using namespace std;

int n;
int l[25], jj[25], dp[105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++) cin >> l[i]; 
	for(int i=0; i<n; i++) cin >> jj[i];
	
	dp[100] = 0; // 체력이 100일 떄 기쁨은 0
	for(int i=0; i<n; i++){
		for(int j=100; j>l[i]; j--){
			dp[j] = max(dp[j], dp[j-l[i]] + jj[i]);
		}
	} 
	
	cout << dp[100] << "\n";
		
	
	
	return 0;
}