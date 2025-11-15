#include <bits/stdc++.h>

using namespace std;

int a[13][13];
vector<pair<int,int>> v;

bool checkrow(int y, int num){
	for(int i=0; i<9; i++){
		if(a[y][i] == num) return false;
	}
	return true;
}

bool checkcol(int x, int num){
	for(int i=0; i<9; i++){
		if(a[i][x] == num) return false;
	}
	return true;
}

int getpos(int pos){
	if(0 <= pos && pos <=2) return 0;
	if(3 <= pos && pos <= 5) return 3;
	if(6 <= pos && pos <= 8) return 6;
}

bool checksquare(int y, int x, int num){
	int ny = getpos(y);
	int nx = getpos(x);
	for(int i=ny; i<ny+3; i++){
		for(int j=nx; j<nx+3; j++){
			if(a[i][j] == num) return false;
		}
	}
	return true;
}

void go(int idx){
	if(idx == v.size()){
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	
	for(int i=1; i<=9; i++){
		int y = v[idx].first;
		int x = v[idx].second;
		// 해당 idx에 i가 들어갈 수 있는지 확인
		// 가로
		if(!checkrow(y,i)) continue;
		// 세로
		if(!checkcol(x,i)) continue;
		// 정사각형 
		if(!checksquare(y,x,i)) continue;
		a[y][x] = i;
		go(idx+1);
		a[y][x] = 0;
	} 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cin >> a[i][j];
			if(a[i][j] == 0){
				v.push_back({i,j});
			}
		}
	}
	
	go(0);
	
	return 0;
}