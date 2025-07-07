#include <bits/stdc++.h>

using namespace std;

int n, two, five;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=2; i<=n; i++){
		int x = i;
		for( ; x%2 == 0; x /= 2) two++;
		for( ; x%5 == 0; x /= 5) five++;
	}
	cout << min(two, five) << "\n";
	
	return 0;
}