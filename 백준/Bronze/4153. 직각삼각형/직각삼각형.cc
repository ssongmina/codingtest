#include <bits/stdc++.h>

using namespace std;

int a,b,c;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(true){
		cin >> a >> b >> c;
		if(a == 0 && b == 0 && c == 0) break;
		vector<int> v;
		v.push_back(a); v.push_back(b); v.push_back(c);
		sort(v.begin(), v.end());
		if(v[2]*v[2] == v[1]*v[1] + v[0]*v[0]) cout << "right\n";
		else cout << "wrong\n";
	}
	
	return 0;
}