#include <bits/stdc++.h>

using namespace std;

int n,y,x;
int arr[105][105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> y >> x;
		for(int j=y; j<y+10; j++){
			for(int k=x; k<x+10; k++){
				arr[j][k] = 1;
			}
		}
	}
	
	int cnt = 0;
	for(int i=1; i<=100; i++){
		for(int j=1; j<=100; j++){
			if(arr[i][j]) cnt++;
		}
	}
	cout << cnt << "\n";
	
	return 0;
}