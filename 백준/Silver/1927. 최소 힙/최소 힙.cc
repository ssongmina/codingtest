#include <bits/stdc++.h>

using namespace std;

int n,x;
priority_queue <int, vector <int>, greater <int>> q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	while(n--){
		cin >> x;
		if(x == 0){
			if(q.empty()) cout << 0 << "\n";
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else{
			q.push(x);
		}
	}
	
	
	return 0;
} 