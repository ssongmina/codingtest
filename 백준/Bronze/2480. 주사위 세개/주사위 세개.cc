#include <bits/stdc++.h>

using namespace std;

int x,ret;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i=0; i<3; i++){
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	if(v[0] == v[1] && v[1] == v[2]){
		ret = 10000+v[0]*1000;
	}else if(v[0] != v[1] && v[1] != v[2] && v[2] != v[0]){
		ret = v[2] * 100;
	}else if(v[0] == v[1] && v[1] != v[2]){
		ret = 1000 + 100*v[0];
	}else if(v[0] != v[1] && v[1] == v[2]){
		ret = 1000 + 100*v[1];
	}
	
	cout << ret << "\n";
	
	return 0;
}