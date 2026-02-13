#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey){
        int last = storey%10;
        storey /= 10;
        if(last == 5){
            if(storey%10 >= 5){
                answer += (10-last);
                storey++;
            }
            else{
                answer += last;
            }
        }
        else if(last < 5){
            answer += last;
        }
        else{
            answer += (10-last);
            storey++;
        }
        
    }
    return answer;
}