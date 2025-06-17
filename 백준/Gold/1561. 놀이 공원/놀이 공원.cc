#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll n, m,lo,hi=60000000004, ret,mid,tmp;
ll arr[10005];


bool check(ll mid){
    tmp = m; 
    for(ll i = 0; i < m; i++)tmp += mid / arr[i];
    return tmp >= n;  
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(ll i=0; i<m; i++){
		cin >> arr[i];
	}
	if(n <= m){
		cout << n;
		return 0;
	}
	
	while(lo <= hi){
		mid = (lo+hi)/2;
		if(check(mid)){
			ret = mid;
			hi = mid - 1;
		}else lo = mid + 1;
	}
	tmp = m;
	for(ll i=0; i<m; i++) tmp += ((ret-1)/arr[i]);
	
	for(ll i=0; i<m; i++){
		if(ret % arr[i] == 0) tmp++;
		if(tmp == n){
			cout << i+1 << "\n";
			return 0;
		}
	}
	
	
	return 0;
}