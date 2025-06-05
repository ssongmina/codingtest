#include <bits/stdc++.h>

using namespace std;

int x;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i=0; i<3; i++){
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	
	int a = v[0] + v[1];
	if(a > v[2]) cout << v[0] + v[1] + v[2] << "\n";
	else{
		cout << 2*(v[0]+v[1])-1 << "\n";
	}
	
	return 0;
}