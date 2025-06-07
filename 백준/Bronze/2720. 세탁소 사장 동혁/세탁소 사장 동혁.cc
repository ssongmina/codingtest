#include <bits/stdc++.h>

using namespace std;

int t,x;
int money[4] = {25, 10, 5, 1};
int arr[7];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// 25 10 5 1
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> x;
		for(int j=0; j<4; j++){
			int ret = x/money[j];
			x = x % money[j];
			cout << ret << " ";
		}
		cout << "\n";
	}
	
	return 0;
}