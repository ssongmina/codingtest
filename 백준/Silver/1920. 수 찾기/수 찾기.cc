#include <bits/stdc++.h>

using namespace std;

int n,x,m;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	
	cin >> m;
	for(int i=0; i<m; i++){
		cin >> x;
		bool flag = false;
		int left = 0, right = v.size()-1;
		while(left <= right){
			int mid = (left+right)/2;
			if(v[mid] == x){
				flag = true;
				break;
			}
			if(v[mid] < x){
				left = mid + 1;
			}
			if(v[mid] > x){
				right = mid - 1;
			}
		}
		if(flag) cout << "1\n";
		else cout << "0\n";
	}
	
	return 0;
}