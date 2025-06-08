#include <bits/stdc++.h>

using namespace std;

int n,k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	queue<int> q;
	for(int i=1; i<=n; i++){
		q.push(i);
	}
	
	cout << "<";
	while(q.size()){
		for(int i=0; i<k-1; i++){
			int x = q.front();
			q.pop();
			q.push(x);
		}	
		cout << q.front();
		if(q.size() != 1) cout << ", ";
		q.pop();
	}
	cout << ">";
	
	
	return 0;
}