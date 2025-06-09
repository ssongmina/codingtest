#include <bits/stdc++.h>

using namespace std;

struct A{
	int r,c,s;
};

int n,m,k,r,c,s,mn=987654321;
int arr[55][55],tmp[55][55];
vector<A> v;
vector<int> vv;
vector<vector<int>> order; // 순열 순서대로 

void swapp(int y, int x, int s, int idx){
	vector<int> ss;
	for(int i=x-s+idx; i<=x+s-idx; i++) ss.push_back(tmp[y-s+idx][i]);
	for(int i=y-s+idx+1; i<=y+s-idx-1; i++) ss.push_back(tmp[i][x+s-idx]);
	for(int i=x+s-idx; i>=x-s+idx; i--) ss.push_back(tmp[y+s-idx][i]);
	for(int i=y+s-idx-1; i>=y-s+idx+1; i--) ss.push_back(tmp[i][x-s+idx]);
	
	rotate(ss.rbegin(), ss.rbegin()+1, ss.rend());
	
	int num = 0;
	for(int i=x-s+idx; i<=x+s-idx; i++) tmp[y-s+idx][i] = ss[num++];
	for(int i=y-s+idx+1; i<=y+s-idx-1; i++) tmp[i][x+s-idx] = ss[num++];
	for(int i=x+s-idx; i>=x-s+idx; i--) tmp[y+s-idx][i] = ss[num++];
	for(int i=y+s-idx-1; i>=y-s+idx+1; i--) tmp[i][x-s+idx] = ss[num++];
	return ;
}

void change(int y, int x, int s){
	for(int i=0; i<s; i++){
		swapp(y,x,s,i);
	}
	return ;
}

void go(vector<int> rotate){ // {0,1,2} 이런식으로 v에서 사용할 순서 
	memcpy(tmp, arr, sizeof(arr));
	for(int i=0; i<rotate.size(); i++){
		int r = v[rotate[i]].r;
		int c = v[rotate[i]].c;
		int s = v[rotate[i]].s;
		change(r,c,s);
	}
	// 각 행별 최솟값 체크 
	for(int i=0; i<n; i++){
		int ret = 0;
		for(int j=0; j<m; j++){
			ret += tmp[i][j];
		}
		mn = min(mn, ret);
	}
	return ;
} 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> k;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}

	for(int i=0; i<k; i++){
		cin >> r >> c >> s;
		v.push_back({--r,--c,s});
		vv.push_back(i);
	}
	
	// 회전 순서 선택
	do{
		order.push_back(vv);
	} while(next_permutation(vv.begin(), vv.end()));
	
	// 회전 연산 
	for(int i=0; i<order.size(); i++){
		go(order[i]);
	}
	
	cout << mn << "\n"; 
	
	return 0;
}