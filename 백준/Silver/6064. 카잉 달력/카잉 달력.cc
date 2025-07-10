#include <bits/stdc++.h>

using namespace std;

int t,m,n,x,y,ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> m >> n >> x >> y;
		while(x <= m*n){
			ans = -1;
			if(x%n == y%n){
				ans = x;
				break;
			}
			else x += m;
		}
		cout << ans << "\n";
	}
	
	return 0;
}