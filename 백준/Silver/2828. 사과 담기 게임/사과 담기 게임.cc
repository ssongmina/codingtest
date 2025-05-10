#include <bits/stdc++.h>

using namespace std;

int n, m, k, x, cnt, p, l, r;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> k;
	l = 1;
	while(k--){
		cin >> x;
		r = l + m - 1;
		if(l <= x && x <= r) continue;
		else if(x < l){
			cnt +=l - x;
			l = x;
		} 
		else if(r < x) {
			l += x - r;
			cnt += x - r;
		}
	}
	cout << cnt << "\n";
	
	return 0;
} 