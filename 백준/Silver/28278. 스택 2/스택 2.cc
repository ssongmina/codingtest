#include <bits/stdc++.h>

using namespace std;

int a,x,n;;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	stack<int> stk;
	for(int i=0; i<n; i++){
		cin >> a;
		if(a == 1){
			cin >> x;
			stk.push(x);
		}else if(a == 2){
			if(stk.size()){
				cout << stk.top() << "\n";
				stk.pop();
			}else cout << "-1\n";
		}else if(a == 3){
			cout << stk.size() << "\n";
		}else if(a == 4){
			if(stk.size()) cout << "0\n";
			else cout << "1\n";
		}else if(a == 5){
			if(stk.size()) cout << stk.top() << "\n";
			else cout << "-1\n";
		}
	}
	
	return 0;
}