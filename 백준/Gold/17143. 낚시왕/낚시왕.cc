#include <bits/stdc++.h>

using namespace std;

struct A{
	int s,d,z;
};
int r,c,m,a,b,s,d,z,sum;
int arr[105][105], tmp[105][105];
vector<A> v;
int dy[5] = {0,-1,1,0,0}, dx[5] = {0,0,0,1,-1};

int fish(int idx){
	for(int i=1; i<=r; i++){
		if(arr[i][idx]){
			int p = v[arr[i][idx]-1].z;
			v[arr[i][idx]-1].s = 0;
			v[arr[i][idx]-1].d = 0;
			v[arr[i][idx]-1].z = 0;
			arr[i][idx] = 0;
			return p;	
		}
	}
	return 0;
}

void move(int y, int x, int idx){
	int s = v[idx].s;
	int d = v[idx].d;
	int z = v[idx].z;

	// 속도 최적화
	if (d == 1 || d == 2) s %= (2 * (r - 1));
	else s %= (2 * (c - 1));

	while (s--) {
		int ny = y + dy[d];
		int nx = x + dx[d];

		if (ny < 1 || ny > r || nx < 1 || nx > c) {
			// 방향 반대로 전환
			if (d == 1) d = 2;
			else if (d == 2) d = 1;
			else if (d == 3) d = 4;
			else if (d == 4) d = 3;
			ny = y + dy[d];
			nx = x + dx[d];
		}
		y = ny;
		x = nx;
	}

	v[idx].d = d;
	
	// 최종 위치에 다른 상어가 있으면?
	if(tmp[y][x]){
		int a = v[idx].z;
		int b = v[tmp[y][x]-1].z;
		if(a > b){
			tmp[y][x] = idx+1;
		}
	}
	else tmp[y][x] = idx + 1;
	return ; 
}

void go(int idx){  // 낚시왕이 idx에 위치 
	// 낚시하기
	sum += fish(idx);

	// 상어 이동
	memset(tmp, 0, sizeof(tmp));
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			if(arr[i][j]) move(i,j,arr[i][j]-1);
		}
	}
	memcpy(arr, tmp, sizeof(tmp));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> r >> c >> m;
	for(int i=1; i<=m; i++){
		cin >> a >> b  >> s >> d >> z;
		arr[a][b] = i;
		v.push_back({s,d,z});
	}
	
	// 낚시와 이동 
	for(int i=1; i<=c; i++){
		go(i);
	}
//	cout << "---- arr ----\n";
//	for(int i=1; i<=r; i++){
//		for(int j=1; j<=c; j++){
//			cout << arr[i][j] << " ";
//		}
//		cout << "\n";
//	} 
//	cout << "------- vector ----- \n";
//	for(auto a : v){
//		cout << a.s << " " << a.d << " " << a.z << "\n";
//	}
	cout << sum << "\n";
	
	return 0;
}