#include <bits/stdc++.h>

using namespace std;

int t,w;
int arr[1005], dp[1005][2][35];

int go(int idx, int tree, int cnt){
	if(cnt < 0) return -1e9;
	if(idx == t) return cnt == 0 ? 0 : -1e9;
	int &ret = dp[idx][tree][cnt];
	if(~ret) return ret;
	return ret = max(go(idx+1, tree^1, cnt-1), go(idx+1,tree,cnt)) + (tree == arr[idx] - 1);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t >> w;
	for(int i=0; i<t; i++){
		cin >> arr[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << max(go(0,1,w-1), go(0,0,w)) << "\n";
	
	return 0;
}