#include <bits/stdc++.h>

using namespace std;

int n,cnt;
string str;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	while(n--){
		cin >> str;
		stack<char> s;
		for(int i=0; i<str.size(); i++){
			if(s.size() == 0) s.push(str[i]);
			else{
				if(s.top() == 'A' && str[i] == 'A') s.pop();
				else if(s.top() == 'B' && str[i] == 'B') s.pop();
				else s.push(str[i]);
			}
		}
		if(s.size() == 0) cnt++;
	}
	cout << cnt << "\n";
	return 0;
}