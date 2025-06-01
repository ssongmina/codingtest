#include <bits/stdc++.h>

using namespace std;

int n,x;
int arr[105];

int main(){
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	cin >> x;
	
	int ret = 0;
	for(int i=0; i<n; i++){
		if(arr[i] == x) ret++;
	}
	cout << ret << "\n";
	
	return 0;
}