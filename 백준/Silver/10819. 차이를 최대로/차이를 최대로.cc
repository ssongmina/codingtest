#include <bits/stdc++.h>

using namespace std;

int n,x,sum;
vector<int> v, v1, v2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
	}
	
	sort(v.begin(), v.end());
	
	do{
		int tmp = 0;
		for(int i=0; i<n-1; i++){
			tmp += abs(v[i] - v[i+1]);
			sum = max(sum, tmp);
		}
	}while(next_permutation(v.begin(), v.end()));
	cout << sum << "\n";
	
	return 0;
}