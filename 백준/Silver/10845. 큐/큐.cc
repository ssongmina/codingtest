#include <bits/stdc++.h>

using namespace std;

int n, x;
string str;
queue<int> q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	while(n--){
		cin >> str;
		if(str == "push"){
			cin >> x;
			q.push(x);
		}
		if(str == "pop"){
			if(q.size()){
				cout << q.front() << "\n"; q.pop();
			}
			else cout << "-1\n";
		}
		if(str == "size") cout << q.size() << "\n";
		if(str == "empty"){
			if(q.size()) cout << "0\n";
			else cout << "1\n";
		}
		if(str == "front"){
			if(q.size()) cout << q.front() << "\n";
			else cout << "-1\n";
		}
		if(str == "back"){
			if(q.size()) cout << q.back() << "\n";
			else cout << "-1\n";
		}
	}
	
	return 0;
}