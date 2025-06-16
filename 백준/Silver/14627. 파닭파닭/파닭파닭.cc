#include <bits/stdc++.h>

using namespace std;

int s,c,x;
long long sum,ret;
vector<int> v;

long long check(long long mid){
	int cnt = 0;
	for(auto a : v){
		cnt += a/mid;
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> s >> c;
	for(int i=0; i<s; i++){
		cin >> x;
		v.push_back(x);
		sum += x;
	}
	
	long long left = 1, right = sum;
	while(left <= right){
		long long mid = (left + right) / 2;
		long long k = check(mid);
		if(k >= c){
			ret = mid;
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	cout << sum - ret *c << "\n";
	
	return 0;
}