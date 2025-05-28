#include <bits/stdc++.h>

using namespace std;

int t,n;
string p, str;
vector<int> v;
deque<string> dq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		dq.clear();
		cin >> p >> n >> str;
		string tmp = "";
		for(int i=0; i<str.size(); i++){
			if('0' <= str[i] && str[i] <= '9') tmp += str[i];
			else{
				if(tmp.size()) dq.push_back(tmp);
				tmp = "";
			}
		}
		bool flag = true;
		bool op = false;
		for(int i=0; i<p.size(); i++){
			if(p[i] == 'R'){
				op = !op;
			}
			else if(p[i] == 'D'){
				if(dq.empty()){
					flag = false;
					break;
				}
				if(!op){
					dq.pop_front();
				}else if(op){
					dq.pop_back();
				}
			}
		}
		
		
		if(op){ // 역방향 
			reverse(dq.begin(), dq.end());
		}
		
		if(flag){
			cout << "[";
			for(auto it = dq.begin(); it != dq.end(); ++it){
				if(it != dq.begin()) cout << ",";
				cout << *it;
			}
			cout << "]";
		}else{
			cout << "error";
		}

		cout << "\n";
		
	}
	
	return 0;
}