#include <bits/stdc++.h>

using namespace std;

int n;
string str;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> str;
	int ret = 0;
	for(int i=0; i<n; i++){
		ret += str[i] - '0';
	}
	cout << ret << "\n";
	
	return 0;
}