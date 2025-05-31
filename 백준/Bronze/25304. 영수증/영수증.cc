#include <bits/stdc++.h>

using namespace std;

int x,n,a,b,ret;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> x >> n;
	while(n--){
		cin >> a >> b;
		ret += a * b;
	}
	if(ret == x) cout << "Yes";
	else cout << "No";
	
	return 0;
}