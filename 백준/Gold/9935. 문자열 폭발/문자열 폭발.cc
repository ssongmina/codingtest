#include <bits/stdc++.h>

using namespace std;

string str, ss;
stack<char> stk;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> str >> ss;
	char c = ss[ss.size()-1];
	
	for(int i=0; i<str.size(); i++){
		if(c != str[i]) stk.push(str[i]);
		else{
			if(stk.size() < ss.size()-1){
				stk.push(str[i]);
				continue; 
			}
			string tmp = "";
			for(int i=0; i<ss.size()-1; i++){
				tmp += stk.top();
				stk.pop();
			}
			reverse(tmp.begin(), tmp.end());
			tmp += c;
			if(tmp == ss) continue;
			for(int i=0; i<tmp.size(); i++) stk.push(tmp[i]);	
		}
	}
	
	string tmp = "";
	while(stk.size()){
		tmp += stk.top();
		stk.pop();
	}
	reverse(tmp.begin(), tmp.end());
	if(tmp.size()) cout << tmp << "\n";
	else cout << "FRULA\n";
	
	return 0;
}