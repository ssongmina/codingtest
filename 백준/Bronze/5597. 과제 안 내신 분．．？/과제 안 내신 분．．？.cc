#include <bits/stdc++.h>

using namespace std;

int x;
int arr[35];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i=0; i<28; i++){
		cin >> x;
		arr[x] = 1;
	}
	
	for(int i=1; i<=30; i++){
		if(arr[i]) continue;
		cout << i << "\n";
	}
	return 0;
}