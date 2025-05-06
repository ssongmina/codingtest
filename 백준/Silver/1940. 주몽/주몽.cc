#include <bits/stdc++.h>

using namespace std;

int n,m,x,cnt;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	
	int pre = 0, suf = v.size()-1;
	while(pre < suf){
		if(v[pre] + v[suf] == m){
			cnt++;
			suf--;
			pre++;
		}
		else if(v[pre] + v[suf] > m) suf--;
		else if(v[pre] + v[suf] < m) pre++;
	}
	cout << cnt << "\n";
	
	return 0;
}