#include <bits/stdc++.h>
#define prev aaa

using namespace std;

int n,ret,lst;
int arr[1004], cnt[1004], prev[1004];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		prev[i] = -1;
	}
	
	for(int i=0; i<n; i++){
		int mx = 0;
		for(int j=0; j<i; j++){
			if(arr[j] < arr[i] && mx < cnt[j]){
				mx = cnt[j];
				prev[i] = j;
			} 
		}
		cnt[i] = mx+1;
		if(ret < cnt[i]){
			ret = cnt[i];
			lst = i;
		}
	}
	
	cout << ret << "\n";
	
	vector<int> v;
	while(lst != -1){
		v.push_back(arr[lst]);
		lst = prev[lst];
	}
	reverse(v.begin(), v.end());
	for(auto a : v) cout << a << " ";
	
	
	
	return 0;
}