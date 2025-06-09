#include <bits/stdc++.h>

using namespace std;

string str;
int t,k,n,d;
int check[1006];
vector<vector<int>> wheel;

void go(int n, int dir){
	memset(check, 0, sizeof(check));
	check[n] = dir;
	for(int i=n; i>0; i--){  // 왼쪽으로 확인 
		if(wheel[i][6] == wheel[i-1][2]) break;
		else{
			if(check[i] == -1) check[i-1] = 1;
			else check[i-1] = -1;
		}
	}
	
	for(int i=n; i<t-1; i++){  // 오른쪽으로 확인 
		if(wheel[i][2] == wheel[i+1][6]) break;
		else{
			if(check[i] == -1) check[i+1] = 1;
			else check[i+1] = -1;
		}	
	}
	
	for(int i=0; i<t; i++){
		if(check[i] == 0) continue;
		else if(check[i] == 1){
			rotate(wheel[i].rbegin(), wheel[i].rbegin()+1, wheel[i].rend());
		}
		else if(check[i] == -1){
			rotate(wheel[i].begin(), wheel[i].begin()+1, wheel[i].end());
		}
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> str;
		vector<int> v;
		for(int i=0; i<str.size(); i++){
			v.push_back(str[i] - '0');
		}
		wheel.push_back(v);
	}
	
	cin >> k;
	for(int i=0; i<k; i++){
		cin >> n >> d;
		go(--n,d); 
	}
	
	// 12시 방향이 S극(1) 몇개? 
	int cnt = 0;
	for(int i=0; i<t; i++){
		if(wheel[i][0] == 1) cnt++;
	}
	cout << cnt << "\n";
	
	return 0;
}