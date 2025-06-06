#include <bits/stdc++.h>

using namespace std;

int a,b,c,d,e,f;

bool check(int x, int y){
	if(a*x + b*y != c) return false;
	if(d*x + e*y != f) return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> a >> b >> c >> d >> e >> f;
	for(int i=-999; i<=999; i++){
		for(int j=-999; j<=999; j++){
			if(check(i,j)) cout << i << " " << j << "\n";
		}
	}
	
	return 0;
}