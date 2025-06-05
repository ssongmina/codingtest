#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(true){
		cin >> n;
		if(n == -1) break;
		v.clear();
		for(int i=1; i<n; i++){
			if(n%i == 0) v.push_back(i);
		}
		int sum = 0;
		for(auto a : v) sum += a;
		if(sum == n){
			cout << n << " = " << v[0];
			for(int i=1; i<v.size(); i++){
				cout << " + " << v[i];
			}
			cout << "\n";
		}
		else cout << n << " is NOT perfect.\n";

	}
	
	
	
	return 0;
}