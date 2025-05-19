#include <bits/stdc++.h>

using namespace std;

int n,ret=-987654321;
string str;
int num[25];
char op[25];

int cal(int a, char c, int b){
	if(c == '+') return a+b;
	if(c == '-') return a-b;
	if(c == '*') return a*b;
	return 0;
}

void go(int idx, int sum){
	// 현재 idx가 범위를 벗어났는지 
	if(idx >= n/2){
		ret = max(ret, sum);
		return ;
	}
	
	int cnt=0;
	// 현재 idx 먼저 계산
	cnt = cal(sum, op[idx], num[idx+1]); 
	go(idx+1, cnt);
	
	if(idx+2 > n/2) return ;
	// 다음 idx 먼저 계산 (괄호 사용)
	cnt = cal(num[idx+1], op[idx+1], num[idx+2]);
	cnt = cal(sum, op[idx], cnt);
	go(idx+2, cnt);
	
	return ; 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> str;
	int idx = 0;
	for(int i=0; i<n; i++){
		if(i%2 == 0) num[idx] = str[i] - '0';
		else{
			op[idx] = str[i];
			idx++;
		}
	}
	
	go(0, num[0]);
	cout << ret << "\n";
	
	return 0;
}