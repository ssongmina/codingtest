#include <bits/stdc++.h>

using namespace std;

int x,k;
string str;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> k;
	stack<int> stk;
	while(k--){
		cin >> x;
		if(x != 0) stk.push(x);
		else stk.pop();
	}
	
	int ret = 0;
	while(stk.size()){
		ret += stk.top();
		stk.pop();
	}
	
	cout << ret << "\n";
	
	return 0;
}