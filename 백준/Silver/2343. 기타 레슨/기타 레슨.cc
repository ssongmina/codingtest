#include <bits/stdc++.h>

using namespace std;

int n,m,x,mx,mn=987654321;
vector<int> v;

bool check(int mid){
	int cnt = 0;
	int sum = 0;
	for(int i=0; i<v.size(); i++){
		if(v[i] > mid) return false;
		sum += v[i];
		if(sum > mid){
			sum = v[i];
			cnt++;
		}
	}
	if(sum <= mid) cnt++;
	return cnt <= m;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
		mx += x;
	}
	
	int left = 0, right = mx;
	while(left <= right){
		int mid = (left + right) / 2;
		if(check(mid)){
			mn = min(mn, mid);
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	
	cout << mn << "\n";
	
	
	return 0;
}