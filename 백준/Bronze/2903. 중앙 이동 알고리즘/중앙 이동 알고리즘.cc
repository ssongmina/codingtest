#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	int k = pow(2,n);
	k+=1;
	cout << k*k << "\n";
	
	return 0;
}