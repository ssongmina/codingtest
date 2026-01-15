#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) { // a개를 가져다주면 b개를 주는 마트
    // a = 3, b = 1, n = 20
    int answer = 0, ret = 0;
    while(true){
        if(n < a) break;
        int get = (n/a) * b; // a개를 줬을때, 받을 수 있는 빈병수 
        answer += get;
        n = n%a + get;
    }
    return answer;
}