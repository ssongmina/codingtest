#include <bits/stdc++.h>

using namespace std;

int t,sum;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i=0; i<9; i++){
		cin >> t;
		sum += t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(i == j) continue;
			if(sum - v[i] - v[j] == 100){
				for(int k=0; k<9; k++){
					if(i == k || j == k) continue;
					cout << v[k] << "\n";
				}
				return 0;
			}
		}
	}
	
	return 0;
}