#include <bits/stdc++.h>

using namespace std;

string str;
char arr[7][17];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i=0; i<5; i++){
		cin >> arr[i];
	}
	
	for(int i=0; i<15; i++){
		for(int j=0; j<5; j++){
			if(arr[j][i] != NULL)
				cout << arr[j][i];
		}
	}
	
	return 0;
}