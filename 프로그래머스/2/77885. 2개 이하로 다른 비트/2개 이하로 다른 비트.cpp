#include <string>
#include <vector>

using namespace std;

bool check(long long a, long long b){
    int dif = 0; // 비트가 다른 개수
    for(int i=0; i<64; i++){
        int aa = a & (1LL<<i);
        int bb = b & (1LL<<i);
        if(aa != bb) dif++;
        if(dif > 2) return false;
    }
    return true;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long number : numbers){
        if(number & 1){ // 홀수인 경우
            long long bit = 1;
            while(number & bit) bit <<= 1;
            answer.push_back(number + bit - (bit >> 1));
        }
        else{ // 짝수인 경우
            answer.push_back(number+1);
        }
    }
    return answer;
}