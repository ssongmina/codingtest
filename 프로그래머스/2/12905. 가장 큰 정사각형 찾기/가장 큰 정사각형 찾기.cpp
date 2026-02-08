#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board) {
    int n = board.size();
    int m = board[0].size();
    int answer = 0;
    if(n < 2 && m < 2){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]) return 1;
            }
        }
        return 0;
    }
    
    vector<vector<int>> dp = board;
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(dp[i][j] == 1){
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                answer = max(answer, dp[i][j]);
            }
        }
    }

    return answer * answer;
}
