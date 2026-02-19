#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if(n&1) return 0;
    long long dp[5005];
    dp[2] = 3L;
    long long sum = 0;
    for(int i=4; i<=n; i+=2){
        dp[i] = (dp[i-2]*3 + sum*2 + 2)%1000000007;
        sum += dp[i-2];
    }
    return (int)dp[n];
}