#include <bits/stdc++.h>

using namespace std;

int n, cnt;
int q[18][18];
vector<pair<int,int>> v;

void go(int idx, int num){
	if(idx == n && num == n){
		cnt++;
		return ;
	}
	for(int i=0; i<n; i++){
		bool flag = true;
		for(auto a : v){
			// 수직인지 확인
			if(a.second == i){
				flag = false;
				break;
			}
			// 수평인지 확인
			if(abs(a.first - idx) == abs(a.second - i)){
				flag = false;
				break;
			}
		}
		if(flag){
			v.push_back({idx, i}); 
			go(idx+1, num+1);	
			v.pop_back();
		} 	 
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	go(0,0);
	cout << cnt << "\n";
	
	return 0;
}