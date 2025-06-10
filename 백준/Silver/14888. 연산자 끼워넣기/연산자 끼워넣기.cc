#include <bits/stdc++.h>

using namespace std;

int n,x;
long long mx=-1000000005, mn = 1000000005;
int num[15];
vector<int> v;
vector<vector<int>> order;

long long cal(long long a, int o, long long b){
	if(o == 0) return a + b;
	if(o == 1) return a - b;
	if(o == 2) return a * b;
	if(o == 3) return a / b;
}

void go(int idx){  // order[idx] 
	long long sum = num[0];
	for(int i=0; i<n-1; i++){
		sum = cal(sum, order[idx][i], num[i+1]);
	}
	mn = min(sum, mn);
	mx = max(sum, mx);
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> num[i];
	}
	for(int i=0; i<4; i++){
		cin >> x;
		for(int j=0; j<x; j++) v.push_back(i);
	}
	
	// 연산자 순서  
	do{
		order.push_back(v);
	} while(next_permutation(v.begin(), v.end()));
	
	for(int i=0; i<order.size(); i++){
		go(i);
	}
	
	cout << mx << "\n" << mn << "\n";
	return 0;
}