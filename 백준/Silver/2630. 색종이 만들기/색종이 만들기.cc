#include <bits/stdc++.h>

using namespace std;

int n, arr[150][150];

pair<int,int> add(pair<int,int> a, pair<int,int> b){
	return {a.first+b.first, a.second+b.second};
}

pair<int,int> go(int y, int x, int size){
	int color = arr[y][x];
	pair<int,int> p = {0,0};
	bool flag = true;
	for(int i=y; i<y+size; i++){
		for(int j=x; j<x+size; j++){
			if(arr[i][j] != color && flag){
				p = add(p, go(y,x,size/2));
				p = add(p, go(y,x+size/2,size/2));
				p = add(p, go(y+size/2,x,size/2));
				p = add(p, go(y+size/2,x+size/2,size/2));
				flag = false;
			}		
		}
	}
	if(flag){
		color == 0 ? p.first++ : p.second++;
	}
	return p;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}
	
	pair<int,int> a = go(0,0,n);
	cout << a.first << "\n" << a.second << "\n";
	
	return 0;
} 