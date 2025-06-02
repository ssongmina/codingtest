#include <bits/stdc++.h>

using namespace std;

int n,m,a,b;
int arr[105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=1; i<=n; i++) arr[i] = i;
	
	for(int i=0; i<m; i++){
		cin >> a >> b;
		
		int tmp[b-a+1];
		for(int j=0; j<=b-a; j++){
			tmp[j] = arr[b-j];
		}
		for(int j=a; j<=b; j++) arr[j] = tmp[j-a];
	}
	
	for(int i=1; i<=n; i++){
		cout << arr[i] << " ";
	}
	
	return 0;
}