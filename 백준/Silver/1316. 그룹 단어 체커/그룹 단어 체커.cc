#include <bits/stdc++.h>

using namespace std;

int n,ret;
string str;
int arr[30];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	while(n--){
		cin >> str;
		memset(arr, 0, sizeof(arr));
		bool flag = true;
		char c = str[0];
		arr[c-'a']++;
		for(int i=1; i<str.size(); i++){
			c = str[i];
			if(arr[c-'a'] && str[i] == str[i-1]) arr[c-'a']++;
			else if(arr[c-'a'] && str[i] != str[i-1]) flag = false;
			else if(!arr[c-'a']) arr[c-'a']++;
		}
		if(flag) ret++;
	}
	cout << ret << "\n";
	
	return 0;
}