#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    long num = n;
    while(num != 1){
        if(num & 1){
            num = num*3 + 1;
        }else{
            num /= 2;
        }
        answer++;
        if(answer > 500) return -1;
    }
    return answer;
}