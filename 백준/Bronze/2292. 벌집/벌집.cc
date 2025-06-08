#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	
	int cnt = 1, layer = 1;
	while(n > cnt){
		cnt += 6*layer;
		layer++;
	}
	cout << layer;
	
	return 0;
}