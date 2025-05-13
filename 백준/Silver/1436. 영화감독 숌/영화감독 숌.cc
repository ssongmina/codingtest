#include <bits/stdc++.h>

using namespace std;

int cnt = 0, n;
string str = "665";

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	
	while(true){
		if(str.find("666") != string::npos){
			cnt++;
		}
		if(cnt == n) break;
		int tmp = stoi(str);
		tmp++;
		str = to_string(tmp);
	}
	cout << str << "\n";
	
	
	return 0;
}