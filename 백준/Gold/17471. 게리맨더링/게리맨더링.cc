#include <bits/stdc++.h>

using namespace std;

int n,aa,x,na,nb,mn=987654321;
int people[15], visited[15];
vector<int> arr[15];
vector<int> a,b;

int go(vector<int> v){
	int sum = 0;
	int cnt = 0;
	queue<int> q;
	q.push(v[0]);
	visited[v[0]] = 1;
	while(q.size()){
		int idx = q.front();
		q.pop();
		sum += people[idx];
		cnt++;
		for(auto next : arr[idx]){
			if(visited[next]) continue;
			if(find(v.begin(), v.end(), next) == v.end()) continue;
			q.push(next);
			visited[next] = 1;
		}
	}
	if(cnt == v.size()) return sum;
	else return -1;
}

void check(){
	if(a.size() == 0 || b.size() == 0) return ; 
	// 두 선거구역이 연결되어 있는지
	memset(visited,0,sizeof(visited));
	int na = go(a);
	memset(visited,0,sizeof(visited));
	int nb = go(b);
	if(na == -1 || nb == -1) return ;
	// 인구 차가 최소인지
	mn = min(mn, abs(na-nb));
	return ; 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> people[i];
	}
	
	for(int i=0; i<n; i++){
		cin >> aa;
		while(aa--){
			cin >> x;
			arr[i].push_back(--x);
		}
	}
	
	for(int i=1; i<(1<<n); i++){
		a.clear(); b.clear();
		for(int j=0; j<n; j++){
			if(i & (1<<j)) a.push_back(j);
			else b.push_back(j);
		}
		check();
	}
	
	if(mn != 987654321)cout << mn << "\n";
	else cout << "-1\n";
	
	return 0;
}