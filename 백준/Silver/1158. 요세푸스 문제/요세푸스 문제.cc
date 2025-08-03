#include <bits/stdc++.h>

using namespace std;

int n,k;
queue<int> q,qq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		q.push(i);
	}
	while(q.size()){
		for(int i=0; i<k-1; i++){
			int x = q.front();
			q.pop();
			q.push(x);
		}
		int x = q.front();
		qq.push(x);
		q.pop();
	}
	
	cout << "<";
	while(qq.size()){
		int x = qq.front();
		cout << x;
		qq.pop();
		if(qq.size()) cout << ", ";
	}
	cout << ">";
	
	return 0;
}