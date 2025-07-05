#include <bits/stdc++.h>

using namespace std;

int n, arr[1000005];

bool check(int num){
	if(num <= 1) return 0;
	if(num == 2) return 1;
	if(num % 2 == 0) return 0;
	for(int i=3; i*i<=num; i++){
		if(num % i == 0) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i=1; i<=1000000; i++){
		if(check(i)) arr[i] = 1;
	}
	
	while(true){
		cin >> n;
		if(n == 0) break;
		bool flag = false;
		for(int i=2; i<=1000000; i++){
			if(arr[i] && arr[n-i]){
				flag = true;
				cout << n << " = " << i << " + " << n-i << "\n";
				break;
			}
		}
		if(!flag) cout << "Goldbach's conjecture is wrong.\n";
	}
	
	return 0;
} 