#include <bits/stdc++.h>

using namespace std;

int n,a;
string name;
vector<pair<int, string>> v;
vector<pair<string, int>> order;

bool cmp(pair<int,string> a, pair<int,string> b){
	return a.first < b.first;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a >> name;
		v.push_back({a,name});
		order.push_back({name,i});
	}
	
	
	stable_sort(v.begin(), v.end(), cmp);
	for(auto a : v)
		cout << a.first << " " << a.second << "\n";
	
	return 0;
}