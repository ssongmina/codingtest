#include <bits/stdc++.h>

using namespace std;

int t,x;
string str;
deque<int> dq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> str;
		if(str == "push_front"){
			cin >> x;
			dq.push_front(x);
		}
		if(str == "push_back"){
			cin >> x;
			dq.push_back(x);
		}
		if(str == "pop_front"){
			if(!dq.size()) cout << "-1\n";
			else{
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		if(str == "pop_back"){
			if(!dq.size()) cout << "-1\n";
			else{
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		if(str == "size"){
			cout << dq.size() << "\n";
		}
		if(str == "empty"){
			if(dq.size()) cout << "0\n";
			else cout << "1\n"; 
		}
		if(str == "front"){
			if(dq.size())
				cout << dq.front() << "\n";
			else cout << "-1\n";
		}
		if(str == "back"){
			if(dq.size())
				cout << dq.back() << "\n";
			else cout << "-1\n";
		}
	}
	
	return 0;
}