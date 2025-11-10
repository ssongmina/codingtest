#include <bits/stdc++.h>

using namespace std;

int n,x,mx;
vector<int> v;

void pick(int sum){
	if(v.size() == 2){
		mx = max(mx, sum);
		return ;
	}
	for(int i=1; i<v.size()-1; i++){
		int tmp = v[i];
		int ttmp = v[i-1] * v[i+1];
		v.erase(v.begin()+i);
		pick(sum + ttmp);
		v.insert(v.begin()+i, tmp);
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
	}
	
	pick(0);
	cout << mx << "\n";
	
	return 0;
}