#include <bits/stdc++.h>

using namespace std;

int n,mn=987654321;
int s[25][25];

int add(vector<int> v){
	int ret = 0;
	for(int i=0; i<v.size(); i++){
		for(int j=i+1; j<v.size(); j++){
			ret += s[v[i]][v[j]] + s[v[j]][v[i]];
		}
	}
	return ret;
}

void go(vector<int> v1, vector<int> v2){
	int sum1 = add(v1);
	int sum2 = add(v2);
	mn = min(mn, abs(sum1-sum2));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> s[i][j];
		}
	}
	
	for(int i=0; i<(1<<n); i++){
		vector<int> v1, v2;
		for(int j=0; j<n; j++){
			if(i & (1<<j)) v1.push_back(j);
			else v2.push_back(j);
		}
		if(v1.size() == v2.size() && v1.size() == n/2) go(v1, v2);
	}
	cout << mn << "\n";
	
	return 0;
}