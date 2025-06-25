#include <bits/stdc++.h>

using namespace std;  // 7-T : 5557번 1학년 

long long n;
long long arr[105], dp[105][21];

long long go(int idx, int sum){
	if(sum < 0 || sum > 20) return 0;
	long long &ret = dp[idx][sum];
	if(ret) return ret;
	if(idx == n-2){
		if(sum == arr[n-1]) return 1;
		return 0;
	}
	ret += go(idx+1, sum + arr[idx+1]);
	ret += go(idx+1, sum - arr[idx+1]);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	} 
	
	cout << go(0, arr[0]) << "\n";
	

	return 0;
}