#include <bits/stdc++.h>

using namespace std;

int n, mn = 987654321, mx = -987654321;
int a[15], op[6];

int cal(int a, int o, int b){
	if(o == 0) return a+b;
	if(o == 1) return a-b;
	if(o == 2) return a*b;
	if(o == 3) return a/b;
	return 0;
}

void go(int idx, int sum){
	if(idx == n){
		mn = min(mn, sum);
		mx = max(mx, sum);
		return ;
	}
	for(int i=0; i<4; i++){ // 연산자 
		if(op[i] == 0) continue;
		op[i]--;
		int nsum = cal(sum, i, a[idx]);
		go(idx+1, nsum);
		op[i]++;
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	for(int i=0; i<4; i++){
		cin >> op[i];
	}
	
	go(1,a[0]);
	cout << mx << "\n" << mn << "\n";
	
	return 0;
}