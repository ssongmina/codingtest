#include <bits/stdc++.h>

using namespace std;

int t,h,w,n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> h >> w >> n;
        int floor = (n % h ? n % h : h);
        int room = n / h + (n % h ? 1 : 0);
        cout << floor;
        if (room < 10) cout << "0";
        cout << room << "\n";
	}
	
	return 0;
}