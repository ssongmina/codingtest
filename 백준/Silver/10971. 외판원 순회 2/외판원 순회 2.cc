#include <bits/stdc++.h>

using namespace std;

int n, ret = 987654321;
int w[15][15], visited[15];

void go(int num, int cnt, int sum){
	// 다 찾는지 확인
	if(cnt == n-1){
		if(w[num][0] == 0) return ;
		ret = min(ret, sum+w[num][0]);
		return ;
	}
	for(int i=1; i<n; i++){
		if(i == num) continue;
		if(visited[i]) continue;
		if(w[num][i] == 0) continue;
		visited[i] = 1;
		go(i, cnt+1, sum+w[num][i]);
		visited[i] = 0;	
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> w[i][j];
		}
	}
	
	go(0, 0, 0);  // 0번에서 출발하기 
	cout << ret << "\n";
	
	return 0;
}