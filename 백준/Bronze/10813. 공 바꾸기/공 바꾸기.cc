#include <bits/stdc++.h>

using namespace std;

int n,m,a,b,x;
int arr[105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		arr[i] = i;
	}
	
	for(int i=0; i<m; i++){
		cin >> a >> b;
		int tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}
	for(int i=1; i<=n; i++){
		cout << arr[i] << " ";
	}
	
	return 0;
}