#include <bits/stdc++.h>

using namespace std;

int n;
string str;
int arr[30][30], visited[30][30];
vector<int> v;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

int dfs(int y, int x){
	int sum = 1;
	visited[y][x] = 1;
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if(!arr[ny][nx] || visited[ny][nx]) continue;
		sum += dfs(ny, nx);
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> str;
		for(int j=0; j<n; j++){
			arr[i][j] = str[j] - '0';
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(arr[i][j] && !visited[i][j]) 
				v.push_back(dfs(i,j));
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for(auto a : v) cout << a << "\n";
	
	
	return 0;
}