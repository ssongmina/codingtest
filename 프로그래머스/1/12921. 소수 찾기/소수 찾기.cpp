#include <string>
#include <vector>

using namespace std;

bool check(int n){
    if(n <= 1) return 0;
    if(n == 2) return 1;
    if(n%2 == 0) return 0;
    for(int i=3; i*i<=n; i++){
        if(n%i == 0) return 0;
    }
    return 1;
}

int solution(int n) {
    int answer = 0;
    for(int i=2; i<=n; i++){
        if(check(i)) answer++;
    }
    return answer;
}