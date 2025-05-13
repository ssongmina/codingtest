#include <bits/stdc++.h>

using namespace std;

string str;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(true){
		getline(cin, str);
		if(str == ".") break;
		
		bool flag = true;
		stack<char> stk;
		for(int i=0; i<str.size(); i++){
			if(str[i] == '(' || str[i] == '[') stk.push(str[i]);
			if(str[i] == ')'){
				if(stk.size() && stk.top() == '(') stk.pop();
				else flag = false;
			}
			if(str[i] == ']'){
				if(stk.size() && stk.top() == '[') stk.pop();
				else flag = false;
			}
		}
		if(stk.size() || !flag) cout << "no\n";
		else cout << "yes\n";
	}
	
	return 0;
}