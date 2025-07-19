#include <bits/stdc++.h>

using namespace std;

int n,ret = 987654321;
int arr[25][25];
vector<int> a, b;

int go(vector<int> v){
	int sum = 0;
	for(int i=0; i<v.size(); i++){
		for(int j=i+1; j<v.size(); j++){
			sum += arr[v[i]][v[j]];
			sum += arr[v[j]][v[i]];
		}
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}
	
	for(int i=1; i<(1<<n); i++){
		
		a.clear(); b.clear();
		for(int j=0; j<n; j++){
			if(i & (1<<j)) a.push_back(j);
			else b.push_back(j);
		}

		if(a.size() < 1 || b.size() < 1) continue;
		ret = min(ret, abs(go(a) - go(b)));
		
	}
	cout << ret << "\n";
	
	return 0;
}