#include <bits/stdc++.h>

using namespace std;

int k, arr[15];

void combi(int idx, vector<int> v){
	if(v.size() == 6){
		for(auto a : v) cout << a << " ";
		cout << "\n";
		return ;
	}
	for(int i=idx+1; i<k; i++){
		v.push_back(arr[i]);
		combi(i, v);
		v.pop_back();
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(true){
		cin >> k;
		if(k == 0) break;
		for(int i=0; i<k; i++){
			cin >> arr[i];
		}
		vector<int> v;
		combi(-1, v);
		cout << "\n";
	}
	
	return 0;
}