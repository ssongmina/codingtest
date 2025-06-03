#include <bits/stdc++.h>

using namespace std;

int chess[6] = {1,1,2,2,2,8};
int x;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i=0; i<6; i++){
		cin >> x;
		if(x == chess[i]) cout << 0 << " ";
		else cout << chess[i] - x << " ";
	}
	
	return 0;
}