#include <bits/stdc++.h>

using namespace std;

int n,x;
int ret[1000005], arr[1000005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
	
	stack<int> stk;
	memset(ret, -1, sizeof(ret));
	for(int i=1; i<=n; i++){
		while(stk.size() && arr[stk.top()] < arr[i]){
			ret[stk.top()] = arr[i];
			stk.pop();
		}
		stk.push(i);
	}
	
	for(int i=1; i<=n; i++){
		cout << ret[i] << " ";
	}
	
	return 0;
}