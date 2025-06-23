#include <bits/stdc++.h>

using namespace std;

int n,c;
double m,p;
vector<pair<int,int>> v;
int dp[10005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(true){
		v.clear();
		fill(dp, dp+10005, 0);
		
		cin >> n >> m;
		if(n == 0 && m == 0.00) break;
		int k = static_cast<int>(m*100 + 0.5);
		int pp;
		for(int i=0; i<n; i++){
			cin >> c >> p;  // 칼로리, 가격 
			pp = static_cast<int>(p*100 + 0.5);
			v.push_back({c,pp});
		}
		
		for(auto a : v){   // 칼로리, 가격 
			for(int i=a.second; i<=k; i++){
				dp[i] = max(dp[i], dp[i-a.second]+a.first);
			}
		}
		
		cout << dp[k] << "\n";
	}
	
	
	return 0;
}