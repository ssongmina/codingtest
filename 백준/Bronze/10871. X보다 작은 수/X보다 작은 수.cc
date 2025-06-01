#include <bits/stdc++.h>

using namespace std;

int n,k,x;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> x;
	for(int i=0; i<n; i++){
		cin >> k;
		if(k < x) cout << k << " ";
	}
	
	return 0;
}