#include <bits/stdc++.h>

using namespace std;

int n,m,t,x,d,k;
vector<vector<int>> circle;

void go(int x, int d, int k){
	// 원판 회전 시키기
	for(int i=x; i<=n; i+=x){
		if(d == 0) 
			rotate(circle[i].rbegin(), circle[i].rbegin()+k, circle[i].rend());
		else if(d == 1)
			rotate(circle[i].begin(), circle[i].begin()+k, circle[i].end());
	}
	
	// 인접한 수 존재 확인 
	set<pair<int,int>> adj;
	for(int i=1; i<=n; i++){
		for(int j=0; j<m; j++){
			if(i<n && circle[i][j] != 0 && circle[i][j] == circle[i+1][j]){
				adj.insert({i,j});
				adj.insert({i+1,j});
			} 
			if(circle[i][j] != 0 && circle[i][(j+1)%m] == circle[i][j]){
				 adj.insert({i,j});
				 adj.insert({i,(j+1)%m});
			}
		}
	}
	if(adj.size()){
		for(auto a : adj)
			circle[a.first][a.second] = 0;
	}
	else{
		int cnt = 0;
		double sum = 0;
		vector<pair<int,int>> c;
		for(int i=1; i<=n; i++){
			for(int j=0; j<m; j++){
				if(circle[i][j] != 0){
					cnt++;
					sum += circle[i][j];
					c.push_back({i,j});
				}
			}
		}
		if(cnt == 0) return;
		sum /= (double)cnt;
		for(auto a : c){
			if(circle[a.first][a.second] > sum) circle[a.first][a.second]--;
			else if(circle[a.first][a.second] < sum) circle[a.first][a.second]++;
		}
	}

	
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> t;
	circle.push_back(vector<int>(m,0)); // idx를 맞추기 위한 
	for(int i=0; i<n; i++){
		vector<int> v;
		for(int i=0; i<m; i++){
			cin >> x;
			v.push_back(x);
		}
		circle.push_back(v);
	}
	for(int i=0; i<t; i++){
		cin >> x >> d >> k;
		go(x,d,k);
	}
	
	int cnt = 0;
	for(int i=1; i<=n; i++){
		for(int j=0; j<m; j++){
			cnt += circle[i][j];
		}
	}
	cout << cnt << "\n";
	
	
	return 0;
}