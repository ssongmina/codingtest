#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	int sum=0, ret= -1001;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		sum += arr[i];
		ret = max(ret, sum);
		if(sum < 0) sum = 0;
	}
	
	cout << ret << "\n";
	
	return 0;
}