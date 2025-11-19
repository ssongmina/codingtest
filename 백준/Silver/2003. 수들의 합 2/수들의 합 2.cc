#include <bits/stdc++.h>

using namespace std;

int n,m,cnt,ret;
int a[10005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			ret += a[j];
			if(ret == m){
				cnt++;
				ret = 0;
				break;
			}
		}
		if(ret != 0) ret = 0;
	}
	cout << cnt << "\n";
	
	return 0;
}