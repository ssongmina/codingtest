#include <bits/stdc++.h>

using namespace std;

int n;
double x;
double arr[10005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
	double ret = arr[0];
	for(int i=1; i<=n; i++){
		arr[i] = max(arr[i], arr[i] * arr[i-1]);
		ret = max(ret, arr[i]);
	}
	cout << fixed << setprecision(3) <<  ret << "\n";
	
	return 0;
}