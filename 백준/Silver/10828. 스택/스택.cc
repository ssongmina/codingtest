#include <bits/stdc++.h>

using namespace std;

int n, x;
string str;
stack<int> stk;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	while(n--){
		cin >> str;
		if(str == "push"){
			cin >> x;
			stk.push(x);
		}
		if(str == "pop"){
			if(stk.size()){
				cout << stk.top() << "\n"; stk.pop();
			}
			else cout << "-1\n";
		}
		if(str == "size"){
			cout << stk.size() << "\n";
		}
		if(str == "empty"){
			if(stk.size()) cout << "0\n";
			else cout << "1\n";
		}
		if(str == "top"){
			if(stk.size()) cout << stk.top() << "\n";
			else cout << "-1\n";
		}
	}
	
	return 0;
}