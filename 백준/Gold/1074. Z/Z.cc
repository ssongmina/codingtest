#include <bits/stdc++.h>

using namespace std;

int n,r,c,ans,cnt;
int arr[20][20];

void go(int y, int x, int size){
	if(size == 1){
		cout << ans << "\n";
		exit(0);
	}
	
	int half = size / 2;
    int area = half * half;

    if (r < y + half && c < x + half) {
        go(y, x, half);
    } else if (r < y + half && c >= x + half) {
        ans += area;
        go(y, x + half, half);
    } else if (r >= y + half && c < x + half) {
        ans += 2 * area;
        go(y + half, x, half);
    } else {
        ans += 3 * area;
        go(y + half, x + half, half);
    }
	
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> r >> c;
	go(0,0,pow(2,n));

	
	return 0;
}