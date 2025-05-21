#include <bits/stdc++.h>

using namespace std;

int n;
char arr[10];	
int num[10];
vector<int> v;
vector<vector<int>> vList;

void go(int cnt, int idx){
	if(cnt == n+1){
		vList.push_back(v);
		return;
	}
	
	for(int i=0; i<10; i++){
		if(num[i])	continue;
		char c = arr[idx];
		if(c == '<'){
			if(v.at(idx) < i){
				v.push_back(i);
				num[i] = 1;
				go(cnt+1, idx+1);
				num[i] = 0;
				v.pop_back();
			}
		}
		else if(c == '>'){
			if(v.at(idx) > i){
				v.push_back(i);
				num[i] = 1;
				go(cnt+1, idx+1);
				num[i] = 0;
				v.pop_back();
			}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	for(int i=0; i<10; i++){
		v.push_back(i);
		num[i] = 1;
		go(1,0);
		num[i] = 0;
		v.pop_back();
	}
	
	sort(vList.begin(), vList.end());
	auto it = vList.back();
	for(int a : it) cout << a;
	cout << "\n";
	it = vList.front();
	for(int a : it) cout << a;
	cout << "\n";
//	cout << vList.back() << "\n" << vList.first() << "\n";
	
}