#include <bits/stdc++.h>

using namespace std;

int n,k,t;
int arr[17][17];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		// k층 n호 
		cin >> k >> n;
		fill(&arr[0][0], &arr[0][0] + 17*17, 0);
		for(int i=1; i<=n; i++) arr[0][i] = i;
		// 각 i층 j호에 대해서 (i-1)층의 1호부터 j호까지의 합
		for(int i=1; i<=k; i++){
			int sum = 0;
			for(int j=1; j<=n; j++){
				sum += arr[i-1][j];
				arr[i][j] = sum;
			}
			
		} 
		cout << arr[k][n] << "\n";
	}
	
	return 0;
}