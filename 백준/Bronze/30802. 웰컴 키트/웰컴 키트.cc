#include <bits/stdc++.h>

using namespace std;

int n,t,p;
int arr[10];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<6; i++) cin >> arr[i];
	cin >> t >> p;
	
	int s = 0;
	for(int i=0; i<6; i++){
		s += arr[i]/t;
		if(arr[i] % t) s++;
	}
	
	cout << s << "\n";
	cout << n/p << " " << n%p << "\n";
	
	return 0;
}