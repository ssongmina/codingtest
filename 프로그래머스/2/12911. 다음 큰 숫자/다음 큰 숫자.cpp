#include <string>
#include <vector>

using namespace std;

int trans(int n){
    int cnt = 0;
    while(n>1){
        if(n%2 == 1) cnt++;
        n /= 2;
    }
    if(n == 1) cnt++;
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int ret = trans(n++);
    while(true){
        if(ret == trans(n)) break;
        n++;
    }
    return n;
}