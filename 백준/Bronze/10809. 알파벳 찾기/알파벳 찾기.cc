#include <bits/stdc++.h>

using namespace std;

int arr[30];
string str;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> str;
	memset(arr, -1, sizeof(arr));
	for(int i=0; i<str.size(); i++){
		if(arr[str[i]-'a'] != -1) continue;
		arr[str[i]-'a'] = i;
	}
	
	for(int i=0; i<26; i++) cout << arr[i] << " ";
	
	return 0;
}