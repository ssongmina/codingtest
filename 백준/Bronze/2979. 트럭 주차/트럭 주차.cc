#include <bits/stdc++.h>

using namespace std;

int a,b,c,s,e,sum;
int arr[104], v[4];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> a >> b >> c;
	for(int i=0; i<3; i++){
		cin >> s >> e;
		for(int j=s; j<e; j++){
			arr[j]++;
		}
	}
	
	for(int i=1; i<=100; i++){
		v[arr[i]]++;
	}
	
	sum += 1 * v[1] * a;
	sum += 2 * v[2] * b;
	sum += 3 * v[3] * c;
	cout << sum << "\n";
	
	return 0;
}