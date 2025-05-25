#include <bits/stdc++.h>

using namespace std;

int n,mp,mf,ms,mv,p,f,s,v,cost;
int a,b,c,d,e,mn=987654321;
struct A{
	int p,f,s,v,cost;
}aa[20];
map<int,vector<vector<int>>> ret_v;

void go(int ret){
	a = b = c = d = e = 0;
	vector<int> vv;
	for(int i=0; i<n; i++){
		if(ret & (1<<i)){
			a += aa[i].p;
			b += aa[i].f;
			c += aa[i].s;
			d += aa[i].v;
			e += aa[i].cost;
			vv.push_back(i+1);
		}
	}
	if(a >= mp && b >= mf && c >= ms && d >= mv){
		if(e <= mn){
			mn = e;
			ret_v[e].push_back(vv);
		}
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	cin >> mp >>  mf >> ms >> mv;
	
	for(int i=0; i<n; i++){
		cin >> aa[i].p >> aa[i].f >> aa[i].s >> aa[i].v >> aa[i].cost;
	}
	
	for(int i=1; i<(1<<n); i++){
		go(i);
	}
	
	if(mn == 987654321) cout << "-1\n";
	else{
		cout << mn << "\n";
		sort(ret_v[mn].begin(), ret_v[mn].end());
		for(auto a : ret_v[mn][0]){
			cout << a << " ";
		}
	}
	
	return 0;
}