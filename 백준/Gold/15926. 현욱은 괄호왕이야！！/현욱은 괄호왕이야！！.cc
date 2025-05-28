#include <bits/stdc++.h>

using namespace std;

int n,ret,cnt;
int d[200001];
string str;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> str;
	stack<int> stk;
	int num = 0;
	
	for(int i=0; i<n; i++){
		if(str[i] == '('){
			stk.push(i);
		}
		else if(stk.size()){
			d[i] = d[stk.top()] = 1;
			stk.pop();
		}
	}
	for(int i=0; i<n; i++){
		if(d[i]){
			ret++;
			cnt = max(cnt, ret);
		}else ret = 0;
	}
	
	cout << cnt << "\n";
	
	return 0;
}

