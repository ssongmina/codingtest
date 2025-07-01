#include <bits/stdc++.h>

using namespace std;

int a, b, c;
int arr[15];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> a >> b >> c;
	int d = a * b * c;
	string str = to_string(d);
	for(int i=0; i<str.size(); i++){
		arr[str[i]-'0']++;
	}
	for(int i=0; i<10; i++) cout << arr[i] << "\n";
	
	return 0;
}