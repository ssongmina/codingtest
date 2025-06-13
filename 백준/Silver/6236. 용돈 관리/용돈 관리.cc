#include <bits/stdc++.h>

using namespace std;

int n,m,x;
vector<int> v;

bool check(int mid){
	int cnt = 1;
	int sum = 0;
	for(int i=0; i<n; i++){
		if(v[i] > mid) return false;
		if(sum + v[i] > mid){
			sum = v[i];
			cnt++;
		}else sum += v[i];
	}
	return cnt <= m;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int left = 0, right = 0;
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
		right += x;
		left = max(left, x);
	}
	int mn = right;
	while(left <= right){
		int mid = (left + right) / 2;
		if(check(mid)){
			mn = mid;
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	
	cout << mn << "\n";
	
	return 0;
}