#include <bits/stdc++.h>

using namespace std;

int x,cnt,ret;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> x;
	ret = 64;
	for(int i=0; i<7; i++){ // 64 = 1000000
		if(x & (1 << i)) cnt ++;
	}
	cout << cnt << "\n";
	
	return 0;
}