#include <bits/stdc++.h>

using namespace std;

int h,w,y,x;
int b[605][605], a[305][305];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> h >> w >> y >> x;
	for(int i=0; i<h+y; i++){
		for(int j=0; j<w+x; j++){
			cin >> b[i][j];
		}
	}
	
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(i >= y && j >= x)
				a[i][j] = b[i][j] - a[i-y][j-x];
			else
				a[i][j] = b[i][j];
		}
	} 
	
	
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}