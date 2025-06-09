#include <bits/stdc++.h>

using namespace std;

int n,k,x;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	deque<int> dq;
	while(n--){
		cin >> k;
		if(k == 1){
			cin >> x;
			dq.push_front(x);
		}
		else if(k == 2){
			cin >> x;
			dq.push_back(x);
		}
		else if(k == 3){
			if(dq.size()) {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else cout << "-1\n";
		}
		else if(k == 4){
			if(dq.size()){
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else cout << "-1\n";
		}
		else if(k == 5){
			cout << dq.size() << "\n";
		}
		else if(k == 6){
			if(dq.size()) cout << "0\n";
			else cout << "1\n";
		}
		else if(k == 7){
			if(dq.size()) cout << dq.front() << "\n";
			else cout << "-1\n";
		}
		else if(k == 8){
			if(dq.size()) cout << dq.back() << "\n";
			else cout << "-1\n";
		}
	}
	
	return 0;
}