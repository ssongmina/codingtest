#include <bits/stdc++.h>

using namespace std;

int n,a,b;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a >> b;
		cout << a + b << "\n";
	}
	
	return 0;
}