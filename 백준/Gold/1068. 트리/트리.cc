#include <bits/stdc++.h>

using namespace std;

int n,root,x;
vector<int> v[55];

int go(int here){
	int cnt = 0, ret = 0;
	for(int there : v[here]){
		if(there == x) continue;
		ret += go(there);
		cnt++;
	}
	if(cnt == 0) return 1;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		if(x == -1) root = i;
		v[x].push_back(i);
	}
	cin >> x;
	
	if(root == x) cout << "0\n";
	else cout << go(root) << "\n";
	
	return 0;
}