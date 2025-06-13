#include <bits/stdc++.h>

using namespace std;

int n,x;
int cnt[10004];
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		cnt[x]++;
	}
	for(int i=1; i<10001; i++){
		for(int j=0; j<cnt[i]; j++) cout << i << "\n";
	}
	
	return 0;
}