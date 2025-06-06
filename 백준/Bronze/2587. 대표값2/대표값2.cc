#include <bits/stdc++.h>

using namespace std;

int x,sum;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i=0; i<5; i++){
		cin >> x;
		v.push_back(x);
		sum += x;
	}
	
	sort(v.begin(), v.end());
	
	cout << sum/5 << "\n";
	cout << v[v.size()/2] << "\n";
	
	
	return 0;
}