#include <bits/stdc++.h>

using namespace std;

int k;
int arr[1050];
vector<int> v[15];

void go(int s, int e, int level){
	if(level == k+1 || s >= e) return ;
	int root = (s+e)/2;
	v[level].push_back(arr[root]);
	
	go(s, root, level+1);
	go(root+1, e, level+1);
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> k;
	for(int i=0; i<pow(2,k)-1; i++){
		cin >> arr[i];
	}
	
	go(0, pow(2,k)-1, 0);
	
	for(int i=0; i<k; i++){
		for(auto a : v[i]) cout << a << " ";
		cout << "\n";
	}
	
	return 0;
}