#include <bits/stdc++.h>

using namespace std;

int n;
int arr[5], scv[65][65][65];
int attack[6][3] = {{1,3,9},{1,9,3},{3,1,9},{3,9,1},{9,1,3},{9,3,1}};
struct A{
	int a,b,c;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	queue<A> q;
	q.push({arr[0],arr[1],arr[2]});
	scv[arr[0]][arr[1]][arr[2]] = 1;
	while(q.size()){
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();
		if(scv[0][0][0]) break;
		for(int i=0; i<6; i++){
			int na = max(0, a - attack[i][0]);
			int nb = max(0, b - attack[i][1]);
			int nc = max(0,  c - attack[i][2]);
			if(scv[na][nb][nc]) continue;
			scv[na][nb][nc] = scv[a][b][c] + 1;
			q.push({na,nb,nc});
		}
	}
	cout << scv[0][0][0] - 1 << "\n";
	
	return 0;
}