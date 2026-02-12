#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
	if(a == 0) return b;
	return gcd(b%a, a);
}

int go(vector<int> v){
    int ret = v[0];
    for(int i=1; i<v.size(); i++){
        ret = gcd(ret, v[i]);
    }
    return ret;
}

int check(int n, vector<int> v){ // 나눠지면 안됨
    for(int i=0; i<v.size(); i++){
        if(v[i] % n == 0) return -1;
    }
    return n;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int a = go(arrayA);
    int b = go(arrayB);
    answer = max(answer, check(a, arrayB));
    answer = max(answer, check(b, arrayA));
    return answer;
}