#include <bits/stdc++.h>

using namespace std;

int n,m,mx;
int arr[105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			for(int k=0; k<j; k++){
				if(arr[i] + arr[k] + arr[j] <= m){
					mx = max(mx, arr[i]+arr[k]+arr[j]);
				}
			}
		}
	}
	
	cout << mx << "\n";
	
	return 0;
}