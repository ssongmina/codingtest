#include <bits/stdc++.h>

using namespace std;

int n,s,sum,ret;
int arr[22];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> s;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	} 
	
	for(int i=1; i<(1<<n); i++){
		int sum = 0;
		for(int j=0; j<n; j++){
			if(i & (1<<j)) sum += arr[j];
		}
		if(sum == s) ret++;
	}
	cout << ret << "\n";
	
	return 0;
}