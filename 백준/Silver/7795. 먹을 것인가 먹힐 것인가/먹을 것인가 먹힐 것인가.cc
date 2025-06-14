#include <bits/stdc++.h>

using namespace std;

int t,n,m,x;
vector<int> a,b;

int check(){
	int ret = 0;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<b.size(); j++){
			if(a[i] > b[j]) ret++;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		a.clear(); b.clear();
		cin >> n >> m;
		for(int i=0; i<n; i++){
			cin >> x;
			a.push_back(x);
		}
		for(int i=0; i<m; i++){
			cin >> x;
			b.push_back(x);
		}
		cout << check() << "\n";
	}

	return 0;
}