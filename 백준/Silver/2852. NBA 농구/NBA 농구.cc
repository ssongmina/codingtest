#include <bits/stdc++.h>

using namespace std;

int n,t,m,s;
int a,b,aSum,bSum,pre;

void go(int num, int cur){
	if(num == 1) aSum += (cur - pre);
	else if(num == 2) bSum += (cur-pre);
}

void change(int sum){
	string str = "--";
	int m = sum / 60;
	int s = sum % 60;
	if(m < 10) cout << "0";
	cout << m << ":";
	if(s < 10) cout << "0";
	cout << s;
}

int main(){
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> t;
		scanf("%d:%d", &m, &s);
		m = m*60+s;
		if(a > b) go(1, m);
		else if(b > a) go(2, m);
		t == 1 ? a++ : b++;
		pre = m;
	}
	if(a > b) go(1,48*60);
	else if(b > a) go(2, 48*60);
	
	change(aSum);
	cout << "\n";
	change(bSum);
	cout << "\n";
	
	return 0;
}