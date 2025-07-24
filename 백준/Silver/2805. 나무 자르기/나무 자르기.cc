#include <bits/stdc++.h>

using namespace std;

long long n,m,mx;
long long arr[1000005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}
	
	long long low = 0, high = mx;
	long long  ret = 0;
	while(low <= high){
		long long mid = (low+high)/2;
		long long cnt = 0;
		for(int i=0; i<n; i++){
			cnt += max(0LL, arr[i] - mid);
		}
		if(cnt >= m){
			low = mid + 1;
			ret = mid;
		}
		else high = mid - 1;
		
	}
	cout << ret << "\n";
	
	return 0;
}