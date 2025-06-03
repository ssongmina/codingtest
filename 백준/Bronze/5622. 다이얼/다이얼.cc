#include <bits/stdc++.h>

using namespace std;

int cnt;
string str;

int check(char c){
	if('A' <= c && c <= 'C') return 3;
	else if('D' <= c && c <= 'F') return 4;
	else if('G' <= c && c <= 'I') return 5;
	else if('J' <= c && c <= 'L') return 6;
	else if('M' <= c && c <= 'O') return 7;
	else if('P' <= c && c <= 'S') return 8;
	else if('T' <= c && c <= 'V') return 9;
	else if('W' <= c && c <= 'Z') return 10;
	else return 11;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> str;
	for(int i=0; i<str.size(); i++){
		cnt += check(str[i]);
	}
	cout << cnt << "\n";
	
	return 0;
}