#include <bits/stdc++.h>

using namespace std;

long long n,m,x,ret;
vector<long long> v;

bool check(long long mid){
	int cnt = 0;
	for(auto a : v){
		cnt += a/mid;
		if(a % mid != 0) cnt++;
	}
	return n >= cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> x;
		v.push_back(x);
	}
	
	sort(v.begin(), v.end());
	long long left = 1, right = v[v.size()-1];
	while(left <= right){
		int mid = (left + right) / 2;
		if(check(mid)){
			ret = mid;
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	
	cout << ret << "\n";
	
	
	return 0;
}