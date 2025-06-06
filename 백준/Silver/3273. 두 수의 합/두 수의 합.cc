#include <bits/stdc++.h>

using namespace std;

int n,x,l,r,cnt;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
	}
	cin >> x;
	
	l = 0,r = n-1;
	sort(v.begin(), v.end());
	
	while(l<r){
		if(v[l] + v[r] == x) r--,cnt++;
		else if(v[l] + v[r] < x) l++;
		else r--;
	}
	
	cout << cnt << "\n";
	return 0;
}
