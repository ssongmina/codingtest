#include <bits/stdc++.h>

using namespace std;

int x,mx,idx;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i=0; i<9; i++){
		cin >> x;
		if(mx < x){
			mx = x;
			idx = i+1;
		}
	}
	cout << mx << "\n" << idx << "\n";
	
	return 0;
}