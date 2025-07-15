#include <bits/stdc++.h>

using namespace std;

int n,x;
vector<int> v, vv;
vector<vector<int>> ret;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
	}
	
	if(next_permutation(v.begin(), v.end())){
		for(int i=0; i<n; i++){
			cout << v[i] << " ";
		}
	}else{
		cout << "-1\n";
	}

	
	return 0;
}