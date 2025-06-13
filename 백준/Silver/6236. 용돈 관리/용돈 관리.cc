#include <bits/stdc++.h>

using namespace std;

int arr[100004];
int n,m,sum,ret,lo,hi,mx;

bool check(int mid){
	int cnt = 1, tmp = mid;
	for(int i=0; i<n; i++){
		if(mid - arr[i] < 0) {
			mid = tmp;
			cnt++;
		}
		mid -= arr[i];
	}
	return cnt <= m;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}
	
	lo = mx, hi = 1000000004;
	while(lo <= hi){
		int mid = (lo + hi) / 2;
		if(check(mid)){
			ret = mid;
			hi = mid - 1;
		} else lo = mid + 1;
	}
	cout << ret << "\n";
	
	return 0;
}