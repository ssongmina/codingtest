#include <bits/stdc++.h>

using namespace std;

int n,atk,t,a,h;
struct A{
	int t,a,h;
};
vector<A> v;

bool check(long long mid){  // mid가 최대 생명력
	long long cur = atk;  // 현재 공격력 
	long long mx = mid;   // 현재 생명력 
	for(int i=0; i<n; i++){
		t = v[i].t;
		a = v[i].a;
		h = v[i].h;
		if(t == 1){
			long long turns = (h+cur-1)/cur;
			long long damage = a * (turns - 1);
			if(mx <= damage) return false;
			mx -= damage;
		}
		else if(t == 2){
			cur += a;
			mx = min(mx+h, mid);
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> atk;  // 초기 공격력:atk 
	for(int i=0; i<n; i++){
		cin >> t >> a >> h;
		v.push_back({t,a,h});
	}
	
	long long left=1, right=9e18;
	long long ret=0;
	while(left <= right){
		long long mid = (left+right)/2;
		if(check(mid)){
			ret = mid;
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	cout << ret << "\n";
	
	return 0;
}