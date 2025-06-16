#include <bits/stdc++.h>

using namespace std;

int n,ret;
int arr[1005], cnt[1004];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	for(int i=0; i<n; i++){
		int mx = 0;
		for(int j=0; j<i; j++){
			if(arr[j] < arr[i] && mx < cnt[j]) mx = cnt[j];
		}
		cnt[i] = mx + 1;
		ret = max(ret, cnt[i]);
	}
	cout << ret << "\n";
	
	return 0;
}

