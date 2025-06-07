#include <bits/stdc++.h>

using namespace std;

int n,x;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
	}
	cin >> x;
	sort(v.begin(), v.end());
	
	int i=0,j=v.size()-1;
	int cnt = 0;
	while(i < j){
		if(v[i] + v[j] == x){
			cnt++;
			i++, j--;
		}
		else if(v[i] + v[j] < x) i++;
		else j--;
	}
	cout << cnt << "\n";
	
	
	return 0;
}