#include <bits/stdc++.h>

using namespace std;

int e,s,m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> e >> s >> m;
	
	int y = e;
	while(!((y-1)%28+1 == s && (y-1)%19+1 == m)) y += 15;
	cout << y << "\n";
	return 0;
}