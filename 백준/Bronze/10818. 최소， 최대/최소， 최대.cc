#include <bits/stdc++.h>

using namespace std;

int n,x,mn=1000005,mx=-1000005;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		mn = min(mn,x);
		mx = max(mx,x);
	}
	cout << mn << " " << mx << "\n";
	
	return 0;
}