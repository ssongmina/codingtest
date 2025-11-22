#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <tuple>
using namespace std; 
int n;
bool check[10001];
bool visited[10001]; 
string s1, s2; 
void init() {
	for (int i = 2; i < 10000; i++ ) {		
		if (check[i] == false) {
			for (int j = i * 2; j < 10000; j += i) {
				check[j] = true; 
			}
		}
	}
}
void dfs() {
	queue <pair<string, int>>q;
	visited[stoi(s1)] = true;
	q.push({ s1, 0 });
	while (!q.empty()) {
		string s; 
		int cnt; 
		tie(s, cnt) = q.front(); 
		q.pop(); 
		if (s == s2) {
			cout << cnt << endl; 
			return; 
		}		 
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j <= 9; j++) {
				string ss = s; 
				ss[i] = j + '0'; 
				if (check[stoi(ss)] == true)continue; //소수아님
				if (visited[stoi(ss)] == true)continue; 
				if (stoi(ss) < 1000 )continue;
				visited[stoi(ss)] = true; 
				q.push({ss, cnt+1 }); 
			}
		}
	}	
	cout << "Impossible" << endl;
}
int main() {
	cin >> n;
	init(); 
	while (n--) {
		cin >> s1 >> s2;
		dfs(); 	
		memset(visited, false, sizeof(visited)); 
	}
}