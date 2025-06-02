#include <bits/stdc++.h>

using namespace std;

int x;
int arr[50];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i=0; i<10; i++){
		cin >> x;
		arr[x%42]++;
	}
	
	int ret = 0;
	for(int i=0; i<42; i++){
		if(arr[i]) ret++;
	}
	cout << ret << "\n";
	
	return 0;
}