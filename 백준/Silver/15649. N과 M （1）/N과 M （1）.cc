#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> ret, sum;

vector<int> check(int idx){
	vector<int> v;
	for(int j=0; j<n; j++){
		if(idx & (1<<j)) v.push_back(j+1);
	}
	return v;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i=1; i<(1<<n); i++){
		vector<int> v = check(i);
		if(v.size() == m) ret.push_back(v);
	}
	
	for(auto a : ret){
		sort(a.begin(), a.end());
		do{
			sum.push_back(a);
		}while(next_permutation(a.begin(), a.end()));
	}
 	
	sort(sum.begin(), sum.end());
	for(auto a : sum){
		for(auto i : a) cout << i << " ";
		cout << "\n";
	}
 	
	return 0;
}