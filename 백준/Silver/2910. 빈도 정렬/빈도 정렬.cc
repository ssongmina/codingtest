#include <bits/stdc++.h>

using namespace std;

int n,c,x;
vector<pair<int,int>> v;
map<int,int> mp_num, mp_order;

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.second == b.second) return mp_order[a.first] < mp_order[b.first];
	return a.second > b.second;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> c;
	for(int i=0; i<n; i++){
		cin >> x;
		auto it = mp_num.find(x);
		if(it != mp_num.end()){
			(*it).second++;
		}else{
			mp_num[x] = 1;
			mp_order[x] = i;
		}
	}
	
	for(auto a : mp_num){
		v.push_back({a.first, a.second});
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(auto a : v){
		for(int i=0; i<a.second; i++)
			cout << a.first << " ";
	}
	
	return 0;
}