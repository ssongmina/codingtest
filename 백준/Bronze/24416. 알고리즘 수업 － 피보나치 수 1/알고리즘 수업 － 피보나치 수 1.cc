#include <bits/stdc++.h>

using namespace std;

int arr[45];
int n,cnt1,cnt2;

int fib(int n){
	if(n == 1 || n == 2){
		cnt1++;
		return 1;
	}
	else return fib(n-1)+fib(n-2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	fib(n);
	
	arr[1] = arr[2] = 1;
	for(int i=3; i<=n; i++){
		arr[i] = arr[i-1] + arr[i-2];
		cnt2++;
	}
	cout << cnt1 << " " << cnt2 << "\n";
	
	return 0;
}