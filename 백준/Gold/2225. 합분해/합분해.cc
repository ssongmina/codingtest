#include <bits/stdc++.h>

using namespace std;

int n,k;
long long dp[205][205];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	
	for(int i=0; i<=k; i++) dp[1][i] = i;

	
	for(int i=2; i<=n; i++){
		for(int j=1; j<=k; j++){
			dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000;
		}
	}
	cout << dp[n][k]<< "\n";
	
	return 0;
}

//0부터 n까지 정수 k개 더해서 n이 나오는 경우의 수 
//
//dp[n][k] : 0부터 n까지 k개의 수를 더해서 n이 나오는 경우의 수
//dp[1][1] = 1, dp[1][2] = 2, dp[1][3] = 3, dp[1][4] = 4;
//dp[2][1] = 1, dp[2][2] = 3, dp[2][3] = 6, dp[2][4] = 10;
//dp[3][1] = 1, dp[3][2] = 4, dp[3][3] = 10, dp[3][4] = 20
//
//dp[a][b] = dp[a][b-1] + dp[a-1][b];
//0 1 2 3
//(0,0,0,3) 4
//(0,0,1,2) 
//(0,1,1,1) 4  
//
//4C2
