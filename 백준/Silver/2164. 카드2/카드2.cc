#include <bits/stdc++.h>

using namespace std;

int n,k,x;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	deque<int> dq;
	for(int i=1; i<=n; i++) dq.push_back(i);
	
	while(dq.size() > 1){
		dq.pop_front();
		int x = dq.front();
		dq.pop_front();
		dq.push_back(x);
		
	}
	
	cout << dq.front() << "\n";
	
	return 0;
}