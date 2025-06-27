#include <bits/stdc++.h>

using namespace std;

int x,sum;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i=0; i<5; i++){
		cin >> x;
		sum += x*x;
	}
	
	cout << sum %10 << "\n";
	
	return 0;
}