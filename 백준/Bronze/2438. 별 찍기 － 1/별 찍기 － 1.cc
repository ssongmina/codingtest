#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<i+1; j++)
			cout << "*";
		cout << "\n";
	}
	
	
	return 0;
}