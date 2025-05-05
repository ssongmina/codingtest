#include <bits/stdc++.h>

using namespace std;

int n;
string ptn, tmp, front, en;

int main(){
	cin >> n;
	cin >> ptn;
	
	int it = ptn.find("*");
	front = ptn.substr(0, it);
	en = ptn.substr(it+1);
	
	for(int i=0; i<n; i++){
		cin >> tmp;
		if(tmp.size() < front.size() + en.size()) cout << "NE\n";
		else if(tmp.substr(0, front.size()) == front && tmp.substr(tmp.size() - en.size()) == en)
			cout << "DA\n";
		else cout << "NE\n";
	}
	return 0;
}