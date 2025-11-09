#include <iostream>
#include <vector>
#include <queue>	
#include <cstring>
using namespace std;
int dir[4][2] = { {1,0}, {-1,0}, { 0,1 }, { 0,-1 } }; //하상 우좌
int arr[6][6];

typedef struct xy {
	int x, y;
}xy;

bool check(int x, int y) {
	return true;
}

int main() {
	bool TF[3] = {false,false,false};
	for (int t = 0; t < 3; t++) {
		vector <int> r[6];
		vector <int> c[6];
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				cin >> arr[i][j];
			}
		}

		//가로 저장
		int rcnt = 0;
		bool rtf = false;
		for (int i = 0; i < 6; i++) {
			rtf = false;
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] == 1) {
					rtf = true;
					r[rcnt].push_back(j);
				}
			}
			if(rtf==true)
			rcnt++;
		}

		//세로 저장
		int ccnt = 0;
		bool ctf = false;
		for (int j = 0; j < 6; j++) {
			ctf = false;
			for (int i = 0; i < 6; i++) {
				if (arr[i][j] == 1) {
					ctf = true;
					c[ccnt].push_back(i);
				}
			}
			if(ctf==true)
			ccnt++;
		}

		//가능한 모든 전개도
		//1. 1 4 1
		//2. 2(모서리에 붙어있어야함) 3 1
		//3. 3 3 (끝과 끝끼리)
		//4. 2 2 2 (계단식으로)

		
		
		if (rcnt == 3) {
			//1. 1 4 1
			if (r[1].size() == 4 && r[0].size() == 1 && r[2].size() == 1)TF[t] = true;

			//2. 2(모서리에 붙어있어야함) 3 1
			
			if (r[1].size() == 3) {
				if (r[0].size() == 2 && (r[0][1] == r[1][0] || r[0][0] == r[1][2]))TF[t] = true;
				else if (r[2].size() == 2 && (r[2][1] == r[1][0] || r[2][0] == r[1][2]))TF[t] = true;
				
			}

			//4. 2 2 2 (계단식으로)
			if (r[0].size() == 2 && r[1].size() == 2 && r[2].size() == 2) {
				if ((r[0][1] == r[1][0] && r[1][1] == r[2][0]) || (r[0][0] == r[1][1] && r[1][0] == r[2][1]))TF[t] = true;
			}

		}

		//3. 3 3 (끝과 끝끼리)
		if (rcnt == 2) {
			if (r[1].size() == 3) {
				if (r[0].size() == 3 && (r[0][2] == r[1][0] || r[0][0] == r[1][2]))TF[t] = true;
			}
		}

		if (ccnt == 3) {
			//1. 1 4 1
			if (c[1].size() == 4 && c[0].size() == 1 && c[2].size() == 1)TF[t] = true;

			//2. 2(모서리에 붙어있어야함) 3 1
			
			if (c[1].size() == 3) {
				if (c[0].size() == 2 && (c[0][1] == c[1][0] || c[0][0] == c[1][2]))TF[t] = true;
				else if (c[2].size() == 2 && (c[2][1] == c[1][0] || c[2][0] == c[1][2]))TF[t] = true;
				
			}

			//4. 2 2 2 (계단식으로)
			if (c[0].size() == 2 && c[1].size() == 2 && c[2].size() == 2) {
				if ((c[0][1] == c[1][0] && c[1][1] == c[2][0]) || (c[0][0] == c[1][1] && c[1][0] == c[2][1]))TF[t] = true;
			}
		}
		//3. 3 3 (끝과 끝끼리)
		if (ccnt == 2) {
			if (c[1].size() == 3) {
				if (c[0].size() == 3 && (c[0][2] == c[1][0] || c[0][0] == c[1][2]))TF[t] = true;
			}
		}


		//cout << "rcnt " << rcnt << endl;
		//for (int i = 0; i < rcnt; i++) {
		//	for (int j = 0; j < r[i].size(); j++) {
		//		cout << r[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		//cout << "ccnt " << ccnt << endl;
		//for (int i = 0; i < ccnt; i++) {
		//	for (int j = 0; j < c[i].size(); j++) {
		//		cout << c[i][j] << " ";
		//	}
		//	cout << endl;
		//}


	}

	for (int i = 0; i < 3; i++) {
		if (TF[i] == true)cout << "yes" << endl;
		else cout << "no" << endl;
	}
	
}