#include <bits/stdc++.h>

using namespace std;

int n;
string str,ss;
char arr[67][67];

string go(int y, int x, int n){
	string tmp = "";	
	char c = arr[y][x];
	for(int i=y; i<y+n; i++){
		for(int j=x; j<x+n; j++){
			if(arr[i][j] != c){ // 분할 해야 하는 경우 
				tmp += "(";
				tmp += go(y,x,n/2);
				tmp += go(y,x+n/2,n/2);
				tmp += go(y+n/2,x,n/2);
				tmp += go(y+n/2,x+n/2,n/2);
				tmp += ")";
				return tmp;
			}
		}
	}
	return string(1,c); 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> str;
		for(int j=0; j<n; j++){
			arr[i][j] = str[j];
		}
	}
	
	ss += go(0,0,n);

	cout << ss << "\n";
	
	return 0;
}