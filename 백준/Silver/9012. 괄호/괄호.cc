#include <bits/stdc++.h>

using namespace std;

int t;
string str;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> str;
		bool flag = true;
		stack<char> stk;
		for(int i=0; i<str.size(); i++){
			if(str[i] == '(') stk.push('(');
			else if(str[i] == ')' && stk.size()){
				stk.pop();
			}
			else flag = false;
		}
		if(stk.size() || !flag) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}