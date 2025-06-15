#include <bits/stdc++.h>
using namespace std;

stack<int> S;
int N, T, cnt=1;

int main(){	
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N; // 학생들의 수. 
	
	while(N--){
		cin >> T;
		
		if(T==cnt) cnt++; // 현재 순번과 일치한다면 보내줘~ 
		else S.push(T); // 아니면 스택에서 기다리도록. 
		
		while(!S.empty()&&S.top()==cnt){
			S.pop();  // 스택 맨 위가 현재 순번과 일치한다면 보내줘~ 
			cnt++;
		}
	}
	
	if(S.empty()) cout << "Nice"; // 스택이 비었다면, 잘 해결된 것. 
	else cout << "Sad";
}
