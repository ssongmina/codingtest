#include <bits/stdc++.h>

using namespace std;

int n,m,r,x;
int arr[105][105], tmp[105][105];
vector<vector<int>> v;

void one(){ // 상하 반전 
	memset(tmp, 0, sizeof(tmp));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			tmp[i][j] = arr[n-i-1][j];
		}
	}
	memcpy(arr, tmp, sizeof(tmp));
}

void two(){ // 좌우 반전 
	memset(tmp, 0, sizeof(tmp));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			tmp[i][j] = arr[i][m-j-1];
		}
	}
	memcpy(arr, tmp, sizeof(tmp));
}

void three(){ // 오른쪽 90도 
	memset(tmp, 0, sizeof(tmp));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			tmp[i][j] = arr[n-j-1][i];
		}
	}
	memset(arr,0,sizeof(arr));
	memcpy(arr, tmp, sizeof(tmp));
	int t = n;
	n = m; m = t;
}

void four(){ // 왼쪽 90도 
	memset(tmp, 0, sizeof(tmp));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			tmp[i][j] = arr[j][m-i-1];
		}
	} 
	memset(arr, 0, sizeof(arr));
	memcpy(arr, tmp, sizeof(tmp));
	int t = n;
	n = m; m = t;
}

vector<int> go(int y, int x, int ys, int xs){
	vector<int> a;
	for(int i=y; i<y+ys; i++){
		for(int j=x; j<x+xs; j++){
			a.push_back(arr[i][j]);
		}
	}
	return a;
}

void make_vec(){
	v.clear();
	v.push_back(go(0,0,n/2,m/2));
	v.push_back(go(0,m/2,n/2,m/2));
	v.push_back(go(n/2,m/2,n/2,m/2));
	v.push_back(go(n/2,0,n/2,m/2));
}

void gogo(int y, int x, int ys, int xs, int idx){
	int cnt = 0;
	for(int i=y; i<y+ys; i++){
		for(int j=x; j<x+xs; j++){
			arr[i][j] = v[idx][cnt++];
		}
	}
}

void toArr(){
	memset(arr, 0, sizeof(arr));
	gogo(0,0,n/2,m/2,0);
	gogo(0,m/2,n/2,m/2,1);
	gogo(n/2,m/2,n/2,m/2,2);
	gogo(n/2,0,n/2,m/2,3);
}

void five(){
	make_vec();
	rotate(v.rbegin(), v.rbegin()+1, v.rend());
	toArr();
}

void six(){
	make_vec();
	rotate(v.begin(), v.begin()+1, v.end());
	toArr();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> r;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}
	for(int i=0; i<r; i++){
		cin >> x;
		if(x == 1) one();
		else if(x == 2) two();
		else if(x == 3) three();
		else if(x == 4) four();
		else if(x == 5) five();
		else if(x == 6) six();
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}


//6 6 1
//1 6 2 9 8 4
//7 2 6 9 8 2
//1 8 3 4 2 9
//7 4 6 2 3 1
//9 2 3 6 1 5
//4 2 9 3 1 8