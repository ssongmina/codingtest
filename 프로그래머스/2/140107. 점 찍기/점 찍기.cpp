#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long rad = (long long)d*d;
    long long y = 0;
    for(int i=0; i<=d; i+=k){
        y = sqrt(rad - (long long)i*i);
        answer += y/(long long)k + 1;
    }
    
    return answer;
}