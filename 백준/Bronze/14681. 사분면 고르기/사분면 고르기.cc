#include <bits/stdc++.h>

using namespace std;

int x,y;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> x >> y;
	if(x > 0 && y > 0) cout << "1";
	else if(x > 0 && y < 0) cout << "4";
	else if(x < 0 && y > 0) cout << "2";
	else if(x < 0 && y < 0) cout << "3";
	
	return 0;
}