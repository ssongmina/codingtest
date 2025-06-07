#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

bool check(int n){
	if(n <= 1) return false;
	if(n == 2) return true;
	if(n % 2 == 0) return false;
	for(int i=3; i*i<=n; i++){
		if(n % i == 0) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=2; i<=n; i++){
		if(check(i)) v.push_back(i);
	}
	if(v.empty()){
		cout << "0\n";
		return 0;
	}
	int i=0, j=0;
	int ret = 0, sum = v[0];
	while(i <= j && j < v.size()){
		if(sum == n){
			ret++;
			sum -= v[i];
			i++;
		}
		else if(sum < n){
			j++;
			if(j >= v.size()) break;
			sum += v[j];
		}
		else if(n < sum){
			sum -= v[i];
			i++;
		}
	}
	
	cout << ret << "\n";
	return 0;
}