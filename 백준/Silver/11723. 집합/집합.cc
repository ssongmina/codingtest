#include <bits/stdc++.h>

using namespace std;

int m,x;
string str;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> m;
	for(int i=0; i<m; i++){
		cin >> str;
		if(str == "add"){
			cin >> x;
			if(find(v.begin(), v.end(), x) == v.end()) v.push_back(x);
		}
		else if(str == "remove"){
			cin >> x;
			auto a = find(v.begin(), v.end(), x);
			if(a != v.end()){
				v.erase(a);
			}
		}
		else if(str == "check"){
			cin >> x;
			if(find(v.begin(), v.end(), x) == v.end()) cout << "0\n";
			else cout << "1\n";
		}
		else if(str == "toggle"){
			cin >> x;
			auto a = find(v.begin(), v.end(), x);
			if(a == v.end()) v.push_back(x);
			else v.erase(a);
		}
		else if(str == "all"){
			v.clear();
			for(int i=1; i<=20; i++){
				v.push_back(i);
			}
		}
		else if(str == "empty"){
			v.clear();
		}
	}
	
	return 0;
}