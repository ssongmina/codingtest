#include <bits/stdc++.h>

using namespace std;

int n,m,x,cnt=1,mx;
vector<pair<int,int>> v;
int dp[45];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	int p = 1;
	for(int i=0; i<m; i++){
		cin >> x;
		v.push_back({p,x});
		mx = max(mx, x-p);
		p = x+1;
	}
	v.push_back({p,n+1}); 
	mx = max(mx, n+1-p);
	
	dp[0] = 1, dp[1] = 1, dp[2] = 2;
	for(int i=3; i<=mx; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	for(auto a : v){
		cnt *= dp[a.second-a.first];
	}
	
	cout << cnt << "\n";
	
	return 0;
}