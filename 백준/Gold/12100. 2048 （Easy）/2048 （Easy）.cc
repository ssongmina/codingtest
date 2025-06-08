#include <bits/stdc++.h>

using namespace std;

int n, mx;
int arr[25][25];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1}; // 위, 오른쪽, 아래, 왼쪽 

void push(int dir) {
    if (dir == 0) { // 위
        for (int x = 0; x < n; x++) {
            vector<int> line;
            for (int y = 0; y < n; y++) {
                if (arr[y][x] != 0) line.push_back(arr[y][x]);
            }
            vector<int> merged;
            for (int i = 0; i < line.size(); i++) {
                if (i+1 < line.size() && line[i] == line[i+1]) {
                    merged.push_back(line[i]*2);
                    i++;
                } else {
                    merged.push_back(line[i]);
                }
            }
            while (merged.size() < n) merged.push_back(0);
            for (int y = 0; y < n; y++) {
                arr[y][x] = merged[y];
            }
        }
    }
    else if (dir == 1) { // 오른쪽
        for (int y = 0; y < n; y++) {
            vector<int> line;
            for (int x = n-1; x >= 0; x--) {
                if (arr[y][x] != 0) line.push_back(arr[y][x]);
            }
            vector<int> merged;
            for (int i = 0; i < line.size(); i++) {
                if (i+1 < line.size() && line[i] == line[i+1]) {
                    merged.push_back(line[i]*2);
                    i++;
                } else {
                    merged.push_back(line[i]);
                }
            }
            while (merged.size() < n) merged.push_back(0);
            for (int x = n-1, i = 0; x >= 0; x--, i++) {
                arr[y][x] = merged[i];
            }
        }
    }
    else if (dir == 2) { // 아래
        for (int x = 0; x < n; x++) {
            vector<int> line;
            for (int y = n-1; y >= 0; y--) {
                if (arr[y][x] != 0) line.push_back(arr[y][x]);
            }
            vector<int> merged;
            for (int i = 0; i < line.size(); i++) {
                if (i+1 < line.size() && line[i] == line[i+1]) {
                    merged.push_back(line[i]*2);
                    i++;
                } else {
                    merged.push_back(line[i]);
                }
            }
            while (merged.size() < n) merged.push_back(0);
            for (int y = n-1, i = 0; y >= 0; y--, i++) {
                arr[y][x] = merged[i];
            }
        }
    }
    else if (dir == 3) { // 왼쪽
        for (int y = 0; y < n; y++) {
            vector<int> line;
            for (int x = 0; x < n; x++) {
                if (arr[y][x] != 0) line.push_back(arr[y][x]);
            }
            vector<int> merged;
            for (int i = 0; i < line.size(); i++) {
                if (i+1 < line.size() && line[i] == line[i+1]) {
                    merged.push_back(line[i]*2);
                    i++;
                } else {
                    merged.push_back(line[i]);
                }
            }
            while (merged.size() < n) merged.push_back(0);
            for (int x = 0; x < n; x++) {
                arr[y][x] = merged[x];
            }
        }
    }
}


void go(int num){
	if(num == 5){
		for (int i=0; i<n; i++)
        	for (int j=0; j<n; j++)
           	 mx = max(mx, arr[i][j]);
		return ;
	}
	int tmp[25][25];
	memcpy(tmp, arr, sizeof(arr));
	// 위, 아래, 오른, 왼 으로 보내기
	for(int i=0; i<4; i++){
		push(i);
		go(num+1);
		memcpy(arr, tmp, sizeof(tmp)); // 원복 
	} 
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}
	
	go(0);
	
	cout << mx << "\n";
	
	return 0;
}