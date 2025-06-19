#include <bits/stdc++.h>

using namespace std;

int t,n;
long long arr[105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	arr[1] = arr[2] = arr[3] = 1;
	while(t--){
		cin >> n;
		if(arr[n] == 0){
			for(int i=4; i<=n; i++){
				arr[i] = arr[i-2] + arr[i-3];
			}
		}
		cout << arr[n] << "\n";
	}
	
	
	return 0;
}