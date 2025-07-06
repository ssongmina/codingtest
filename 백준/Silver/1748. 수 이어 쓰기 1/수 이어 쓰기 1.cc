#include <bits/stdc++.h>

using namespace std;

int n, sum;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	sum += (n<=9 ? n : 9);
	if(n > 9){
		int now = 99, s = 2, pr = 9;
		while(true){
			if(n <= now){
				sum += (n-pr) * s;
				break;
			}else if(n > now){
				sum += (now-pr) * s;
			}
			s++;
			pr = pr*10 + 9;
			now = now*10 + 9;
		}
	}
	cout << sum << "\n";
	
	return 0;
}