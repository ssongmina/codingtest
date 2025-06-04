#include <bits/stdc++.h>

using namespace std;

int x,n;;
string str;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	queue<int> q;
	for(int i=0; i<n; i++){
		cin >> str;
		if(str == "push"){
			cin >> x;
			q.push(x);
		}else if(str == "pop"){
			if(q.size()){
				cout << q.front() << "\n";
				q.pop();
			}else cout << "-1\n";
		}else if(str == "size"){
			cout << q.size() << "\n";
		}else if(str == "empty"){
			if(q.size()) cout << "0\n";
			else cout << "1\n";
		}else if(str == "front"){
			if(q.size()) cout << q.front() << "\n";
			else cout << "-1\n";
		}else if(str == "back"){
			if(q.size()) cout << q.back() << "\n";
			else cout << "-1\n";
		}
	}
	
	return 0;
}