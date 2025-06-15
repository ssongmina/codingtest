#include <bits/stdc++.h>

using namespace std;

int x,y;

bool check(int mid){
	int z = (long long)y*100/x;
	int nz = (long long)(y+mid)*100/(x+mid);
	return z != nz;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> x >> y;
	if((long long)y*100/x >= 99) cout << "-1\n";
	else{
		int left = 0, right = 1000000000, ret = 0;
		while(left <= right){
			int mid = (left+right)/2;
			if(check(mid)){
				ret = mid;
				right = mid - 1;
			}
			else{
				left = mid + 1;
			}
		}
		cout << ret << "\n";
	}
	
	return 0;
}