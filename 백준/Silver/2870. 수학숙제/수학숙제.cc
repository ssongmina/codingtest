#include <bits/stdc++.h>

using namespace std;

int n;
string str, tmp;
vector<string> v;

void go(string tmp){
	if(tmp[0] == '0'){
		int idx = 0;
		for(int i=0; i<tmp.size(); i++){
			if(tmp[i] == '0') idx = i;
			else break;
		}
		if(idx == tmp.size()-1) tmp = "0";
		else tmp.erase(0, idx+1);
	}
	v.push_back(tmp);
	return ;
}

bool cmp(string a, string b){
	if(a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	while(n--){
		cin >> str;
		tmp = "";
		for(int i=0; i<str.size(); i++){
			if('a' <= str[i] && str[i] <= 'z'){
				if(tmp.size()) go(tmp);
				tmp = "";
			}else{
				tmp += str[i];
			}
		}
		if(tmp.size()) go(tmp); 
	}
	
	sort(v.begin(), v.end(), cmp);
	for(auto a : v) cout << a << "\n";
	
	return 0;
}