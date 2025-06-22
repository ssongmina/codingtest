#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll n,k,x;
vector<ll> v;
ll dp[10006];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
	}
	
	dp[0] = 1;
	for(auto a : v){
		for(int i=a; i<k+1; i++){
			dp[i] += dp[i-a];
		}
	}
	
	cout << dp[k] << "\n";
	
	return 0;
}