#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1000005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	arr[1] = 1;
	arr[2] = 2;
	for(int i=3; i<n+1; i++){
		arr[i] = (arr[i-1]+arr[i-2]) % 15746;
	}
	cout << arr[n];
	
	return 0;
}