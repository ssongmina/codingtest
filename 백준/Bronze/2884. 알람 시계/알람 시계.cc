#include <bits/stdc++.h>

using namespace std;

int h,m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> h >> m;
	if(m >= 45) m-= 45;
	else{
		int s = 45 - m;
		m = 60 - s;
		h--;
		if(h < 0) h = 23;
	}
	cout << h << " " << m;
	
	return 0;
}