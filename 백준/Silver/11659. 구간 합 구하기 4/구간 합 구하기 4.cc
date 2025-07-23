#include <bits/stdc++.h>

using namespace std;

int n,m,a,b;
int arr[100005], psum[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
		psum[i] = psum[i-1] + arr[i];
	}
	for(int i=0; i<m; i++){
		cin >> a >> b;
		cout << psum[b] - psum[a-1] << "\n";
	}
	
	
	
	return 0;
}