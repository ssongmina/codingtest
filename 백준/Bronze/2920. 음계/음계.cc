#include <bits/stdc++.h>

using namespace std;

int x, arr[10];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i=0; i<8; i++){
		cin >> arr[i];
	}
	
	int prev = arr[0];
	int up = 0, down = 0;
	for(int i=1; i<8; i++){
		if(prev < arr[i]) down++;
		else if(prev > arr[i]) up++;
		prev = arr[i];
	}
	if(up == 0 && down != 0) cout << "ascending\n";
	else if(up != 0 && down == 0) cout << "descending\n";
	else cout << "mixed\n";
	
	return 0;
}