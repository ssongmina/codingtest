#include <bits/stdc++.h>

using namespace std;

int a,b,sum,mn=987654321;

bool check(int n){
	if(n <= 1) return 0;
	if(n == 2) return 1;
	if(n % 2 == 0) return 0;
	for(int i=3; i*i<=n; i++){
		if(n%i == 0) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> a >> b;
	for(int i=a; i<=b; i++){
		if(check(i)){
			mn = min(mn, i);
			sum += i;
		}
	}
	
	if(sum == 0) cout << "-1\n";
	else cout << sum << "\n" << mn << "\n";
	
	return 0;
}