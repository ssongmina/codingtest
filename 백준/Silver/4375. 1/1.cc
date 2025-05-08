#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
	
	while(scanf("%d", &n) != EOF){
		int ret = 1, cnt = 1;
		while(ret % n != 0){
			ret = ret * 10 + 1;
			ret = ret % n;
			cnt++;
		}	
		cout << cnt << "\n";
	}

	return 0;
}