#include <bits/stdc++.h>

using namespace std;

int n, mn=987654321;
string str;
int arr[25][25];

void go(int num){
	for(int i=0; i<n; i++){
		if(num & (1<<i)){  // i번째 가로줄을 바꾸어야 하는 경우 
			for(int j=0; j<n; j++){
				arr[i][j] = (arr[i][j] == 1 ? 0 : 1);
			} 
		}
	}
	return ;
} 

int check(){
	int sum = 0;
	for(int i=0; i<n; i++){
		int cnt = 0;
		for(int j=0; j<n; j++){
			if(arr[j][i] == 1) cnt++;
		}
		cnt = min(cnt, n-cnt);
		sum += cnt;
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> str;
		for(int j=0; j<n; j++){
			if(str[j] == 'H') arr[i][j] = 1;
		}
	}
	
	for(int i=0; i<(1<<n); i++){  // 가로줄을 뒤집을 수 있는 모든 경우의 수 
		go(i);
		
		mn = min(mn,check());
		
		go(i); // 원복 
	}
	
	cout << mn << "\n";
	
	return 0;
}