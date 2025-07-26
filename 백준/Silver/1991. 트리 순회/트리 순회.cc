#include <bits/stdc++.h>

using namespace std;

int n;
int arr[30][5];
char a,b,c;

void pre_order(int here){
	cout << (char)(here + 'A');
	if(arr[here][0]){
		pre_order(arr[here][0]);
	}
	if(arr[here][1]){
		pre_order(arr[here][1]);
	}
	return ;
}

void mid_order(int here){
	if(arr[here][0]){
		mid_order(arr[here][0]);
	}
	cout << (char)(here+'A');
	if(arr[here][1]){
		mid_order(arr[here][1]);
	}
	return ;
}

void end_order(int here){
	if(arr[here][0]){
		end_order(arr[here][0]);
	}
	if(arr[here][1]){
		end_order(arr[here][1]);
	}
	cout << (char)(here+'A');
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a >> b >> c;
		if(b != '.') arr[a-'A'][0] = b-'A';
		if(c != '.') arr[a-'A'][1] = c-'A';
	}
	
	pre_order(0); 
	cout << "\n";
	mid_order(0);
	cout << "\n";
	end_order(0);
	cout << "\n";
	
	return 0;
}