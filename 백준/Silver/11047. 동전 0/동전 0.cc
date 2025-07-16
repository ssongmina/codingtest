#include <bits/stdc++.h>

using namespace std;

int n,k,x,sum;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
	}
	
	sort(v.rbegin(), v.rend());
	
	while(true){
		if(k == 0) break;
		for(auto a : v){
			if(k / a){
				sum += k/a;
			}
			k = k%a;
		}
	}
	cout << sum << "\n";
	
	return 0;
}