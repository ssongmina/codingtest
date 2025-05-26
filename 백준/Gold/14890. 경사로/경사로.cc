#include <bits/stdc++.h>

using namespace std;

int n,l,ret;
int arr[105][105], brr[105][105];

void go(int a[105][105]){
	for(int i=0; i<n; i++){
		int cnt = 1;
		int j;
		for(j=0; j<n-1; j++){
			if(a[i][j] == a[i][j+1]) cnt++;
			else if(a[i][j] + 1 == a[i][j+1] && cnt >= l) cnt = 1;
			else if(a[i][j] == a[i][j+1] + 1 && cnt >= 0) cnt = 1 - l;
			else break;  
		}
		if(j == n-1 && cnt >= 0) ret++;
	}
	return ;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> l;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
			brr[j][i] = arr[i][j];
		}
	}
	
	go(arr);
	go(brr);
	cout << ret << "\n";
	
	return 0;
}