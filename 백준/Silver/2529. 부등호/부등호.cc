#include <bits/stdc++.h>

using namespace std;

int k;
int numb[13];
char arr[13];
vector<string> v;

bool cmp(string a, string b){
	if(a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

bool check(char a, char c, char b){
	if(c == '>') return a > b;
	else if(c == '<') return a < b;
	return false;
}

void go(string num, int idx){
	if(idx == k+1){
		v.push_back(num);
		return ;
	}
	for(int i=0; i<10; i++){
		// 해당 숫자 사용했는지 확인
		if(numb[i]) continue;
		
		// 부등호 기호에 알맞는 숫자인지
		if(idx == 0 || check(num[idx-1], arr[idx-1], i+'0')){
			numb[i] = 1;
			go(num+to_string(i), idx+1);
			numb[i] = 0;
		}
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> k;
	for(int i=0; i<k; i++) cin >> arr[i];

	go("",0);
	
	sort(v.begin(), v.end(), cmp);
	cout << v[v.size()-1] << "\n" << v[0] << "\n";
	return 0;
}