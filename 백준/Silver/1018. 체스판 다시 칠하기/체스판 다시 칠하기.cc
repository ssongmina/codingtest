#include <bits/stdc++.h>

using namespace std;

int n,m,mn=100;
string str;
int arr[60][60];

int tmp1[8][8] = {{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1}};

void check(int y, int x){
	int cnt = 0;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(arr[i+y][j+x] != tmp1[i][j]) cnt++;
		}
	}
	cnt = min(cnt, 64-cnt);
	mn = min(mn, cnt);
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> str;
		for(int j=0; j<m; j++){
			if(str[j] == 'W') arr[i][j] = 1;
			else if(str[j] == 'B') arr[i][j] = 0;
		}
	} 
	
	for(int i=0; i<=n-8; i++){
		for(int j=0; j<=m-8; j++){
			check(i,j);
		}
	}
	
	cout << mn << "\n";
	
	
	return 0;
}