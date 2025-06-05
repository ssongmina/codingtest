#include <bits/stdc++.h>

using namespace std;

int n,mx_x=-10005,mx_y=-10005,y,x;
int mn_y=10005,mn_x=10005;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> y >> x;
		mx_x = max(x,mx_x);
		mx_y = max(y,mx_y);
		mn_x = min(x,mn_x);
		mn_y = min(y,mn_y);
	}
	
	cout << (mx_x-mn_x) * (mx_y-mn_y) << "\n";
	
	return 0;
}