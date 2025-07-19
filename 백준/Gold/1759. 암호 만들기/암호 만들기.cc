#include <bits/stdc++.h>

using namespace std;

int l,c;
char x;
vector<char> v, vv;
vector<string> ret;

bool check(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void go(int idx, vector<char> vv, int ja, int mo){
	if(idx == c){
		if(vv.size() != l) return ;
		if(ja < 1) return ;
		if(mo < 2) return ;
		string str = "";
		for(auto a : vv) str += a;
		ret.push_back(str);
		return ;
	}
	
	// 현재 idx를 말래 
	go(idx+1, vv, ja, mo);
	
	// 현재 idx를 할래
	vv.push_back(v[idx]);
	if(check(v[idx])) ja++;
	else mo++;
	go(idx+1, vv, ja, mo);
	vv.pop_back();
	
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> l >> c;
	for(int i=0; i<c; i++){
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	
	go(0, vv, 0, 0);
	
	sort(ret.begin(), ret.end());
	for(auto a : ret) cout << a << "\n";
	
	return 0;
}