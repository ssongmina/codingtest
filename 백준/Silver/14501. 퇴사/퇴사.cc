#include <bits/stdc++.h>

using namespace std;

int n, ret;
int t[20], p[20], visited[20];

void go(vector<int> v){
	memset(visited, 0, sizeof(visited));
	int sum = 0;
	for(auto a : v){
		if(a+t[a] > n) return ;
		for(int i=a; i<a+t[a]; i++){
			if(visited[i]) return ;
			visited[i] = 1;
		}
		sum += p[a];
	}
	ret = max(ret, sum);
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> t[i] >> p[i];
	}
	
	for(int i=1; i<(1<<n); i++){
		vector<int> v;
		for(int j=0; j<n; j++){
			if(i & (1<<j)) v.push_back(j);
		}
		go(v);
	}
	cout << ret << "\n";
	
	return 0;
} 