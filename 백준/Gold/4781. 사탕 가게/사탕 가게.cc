#include <bits/stdc++.h>

using namespace std;

int n,m1,m2,a,b1,b2,b,m;
vector<pair<int,int>> v;
int dp[10005];

int main(){
	
	while(true){
		scanf("%d %d.%d", &n, &m1, &m2);
		if(n == 0 && m1 == 0 && m2 == 0) break;
		v.clear();
		m = m1*100 + m2; // 상근이의 존
		for(int i=0; i<n; i++){
			scanf("%d %d.%d", &a, &b1, &b2);
			b = b1*100 + b2;
			v.push_back({a,b});  // 칼로리, 가격 
		}	
		fill(dp, dp+10005, 0);
		for(auto k : v){
			for(int i=k.second; i<=m; i++){
				dp[i] = max(dp[i], dp[i-k.second] + k.first);
			}
		}
		cout << dp[m] << "\n";
	}
	
	
	
	return 0;
}