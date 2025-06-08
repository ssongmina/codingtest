#include <bits/stdc++.h>

using namespace std;

string n;
int b;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> b;
	
	int sum = 0;
	for(int i=0; i<n.size(); i++){
		int digit;
		if ('0' <= n[i] && n[i] <= '9')
            digit = n[i] - '0';
        else
            digit = n[i] - 'A' + 10;
        sum = sum * b + digit;
	}
	
	cout << sum << "\n";
	
	return 0;
}