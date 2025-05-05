#include <bits/stdc++.h>

using namespace std;

int n,k,x,mx=-987654321;
int psum[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> x;
		psum[i] = psum[i-1] + x;
	}
	
	for(int i=0; i<n-k+1; i++){
		mx = max(psum[i+k]- psum[i], mx);
	}
	cout << mx << "\n";
	
	return 0;
}