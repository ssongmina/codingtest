#include <bits/stdc++.h>

using namespace std;

int a,y,x,mx=-1;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i=1; i<=9; i++){
		for(int j=1; j<=9; j++){
			cin >> a;
			if(mx <= a){
				mx = a;
				y = i, x = j;
			}
		}
	}
	
	cout << mx << "\n";
	cout << y << " " << x;
	
	return 0;
}