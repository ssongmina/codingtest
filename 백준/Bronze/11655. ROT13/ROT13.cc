#include <bits/stdc++.h>

using namespace std;

string s, tmp;

int check(char c){
	if('a' <= c && c <= 'z') return 2;
	if('A' <= c && c <= 'Z') return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	getline(cin, s);
	for(int i=0; i<s.size(); i++){
		if(check(s[i]) == 2){
			if(s[i] + 13 > 'z') cout << (char)('a' + s[i] + 12 - 'z');
			else cout << (char)(s[i] + 13);
		}
		else if(check(s[i]) == 1){
			if(s[i] + 13 > 'Z') cout << (char)('A' + s[i] + 12 - 'Z');
			else cout << (char)(s[i] + 13);	
		}
		else cout << s[i];
			
	}
	
	
	return 0;
}