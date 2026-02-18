#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    for(int i=0;i<=r2;i++){
        long long y1;
        if(r1>=i)
            y1 = (long long)ceil(sqrt(pow(r1, 2)-pow(i, 2)));
        else
            y1 = 0;
        long long y2 = (long long)floor(sqrt(pow(r2, 2)-pow(i, 2)));
        answer+=y2-y1+1;
    }
    answer*=4;
    answer-=(r2-r1+1)*4;
    return answer;
}