#include <bits/stdc++.h>

using namespace std;

int a,b;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> a >> b;
	cout << a * (b%10) << "\n";
	cout << a * ((b%100)/10) << "\n";
	cout << a * (b/100) << "\n";
	cout << a * b << "\n";
	
	return 0;
}