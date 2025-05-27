#include <bits/stdc++.h>

using namespace std;

string str;
int x, m;
int val = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> m;
	while(m--){
		cin >> str;
		if(str == "add"){
			cin >> x;
			val |= (1<<x);
		}
		else if(str == "remove"){
			cin >> x;
			val &= ~(1<<x);
		}
		else if(str == "check"){
			cin >> x;
			if(val & (1<<x)) cout << "1\n";
			else cout << "0\n";
		}
		else if(str == "toggle"){
			cin >> x;
			if(val & (1<<x)) val &= ~(1<<x);
			else val |= (1<<x);
		}
		else if(str == "all"){
			val = (1<<21) - 1;
		}
		else if(str == "empty"){
			val = 0;
		}
	}
	
	return 0;
}