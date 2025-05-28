#include <bits/stdc++.h>

using namespace std;

string a,b;

string add(string a, string b){
	int num = 0;
	string sum;
	while(a.size() || b.size() || num){
		if(a.size()){
			num += a.back() - '0';
			a.pop_back();
		}
		if(b.size()){
			num += b.back() - '0';
			b.pop_back();
		}
		sum += (num%10) + '0';
		num /= 10;
	}
	reverse(sum.begin(), sum.end());
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> a >> b;

	cout << add(a,b);
	
	return 0;
}