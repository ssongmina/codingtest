#include <bits/stdc++.h>

using namespace std;

double ret;
int n,x,mx;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
		mx = max(mx, x);
	}
	
	for(auto a : v){
		double d = (double)a/mx*100;
		ret += d;
	}
	
	cout << fixed << setprecision(6) << ret/n << "\n";
	
	
	return 0;
}