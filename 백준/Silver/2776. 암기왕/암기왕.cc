#include <bits/stdc++.h>

using namespace std;

int t,n,m,x;
vector<int> v;

int check(int x){
	int left = 0; int right = v.size()-1;
	while(left <= right){
		int mid = (left+right)/2;
		if(v[mid] == x) return 1;
		else if(v[mid] < x) left = mid + 1;
		else right = mid - 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		v.clear();
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		cin >> m;
		for(int i=0; i<m; i++){
			cin >> x;
			cout << check(x) << "\n";
		}
	}
	
	
	return 0;
}