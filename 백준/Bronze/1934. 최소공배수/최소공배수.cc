#include <bits/stdc++.h>

using namespace std;

int n,a,b;

int gcd(int a, int b){
	if(a == 0) return b;
	return gcd(b%a,a);
}

int lcd(int a, int b){
	return (a*b) / gcd(a,b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	while(n--){
		cin >> a >> b;
		cout << lcd(a,b) << "\n";
	}

	return 0;
}