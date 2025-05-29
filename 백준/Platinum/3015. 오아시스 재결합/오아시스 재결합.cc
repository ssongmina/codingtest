#include <bits/stdc++.h>

using namespace std;
long long n, ret, tmp;
stack<pair<long long, long long>> s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> tmp;
		int cnt = 1;
		while(s.size() && s.top().first <= tmp){
			ret += s.top().second;
			if(s.top().first == tmp){
				cnt = s.top().second+1;
			}else{
				cnt = 1;
			}
			s.pop();
		}
		if(s.size()) ret++;
		s.push({tmp, cnt});
	}
	cout << ret << "\n";
	
	
	return 0;
}