#include <bits/stdc++.h>

using namespace std;

int n,cnt;
string str;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	int i=2;
	while(n > 1){
		if(n % i == 0){
			n = n/i;
			cout << i << "\n";
		}
		else i++;
	}

	
	return 0;
}