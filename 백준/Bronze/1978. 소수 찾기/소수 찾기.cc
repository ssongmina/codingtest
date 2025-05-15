#include <bits/stdc++.h>

using namespace std;

int n,x,cnt;

int check(int x){
	if(x <= 1) return 0;
	if(x == 2) return 1;
	if(x % 2 == 0) return 0;
	for(int i=3; i*i<=x; i++){
		if(x % i == 0) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	while(n--){
		cin >> x;
		cnt += check(x);
	}
	cout << cnt << "\n";
	
	return 0;
}