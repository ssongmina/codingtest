#include <bits/stdc++.h>

using namespace std;

int f[40] = {0,5,13},n;
string s = "Messi Gimossi";

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	n--;
	for(int i=3; i<=39; i++){
		f[i] = f[i-1] + f[i-2] + 1;
	}
	for(int i=39; i>=2; i--){
		if(n >= f[i]) n -= (f[i] + 1);
	}
	
	if(n == 5 || n == -1) cout << "Messi Messi Gimossi\n";
	else cout << s[n] << "\n"; 
	
	
	return 0;
}