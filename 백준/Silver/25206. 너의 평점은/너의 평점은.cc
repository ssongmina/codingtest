#include <bits/stdc++.h>

using namespace std;

string str,ss;
double x,sum,ret;

double check(string ss){
	if(ss == "A+") return 4.5;
	else if(ss == "A0") return 4.0;
	else if(ss == "B+") return 3.5;
	else if(ss == "B0") return 3.0;
	else if(ss == "C+") return 2.5;
	else if(ss == "C0") return 2.0;
	else if(ss == "D+") return 1.5;
	else if(ss == "D0") return 1.0;
	else if(ss == "F") return 0.0;
	
	return 0.0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	//(학점*과목평점)의 합 / 학점의 총합 
	for(int i=0; i<20; i++){
		cin >> str >> x >> ss;
		if(ss == "P") continue;
		double p = check(ss);
		sum += p*x;
		ret += x;
	}
	
	cout << fixed << setprecision(15) << (double)sum / ret << "\n";
	
	return 0;
}