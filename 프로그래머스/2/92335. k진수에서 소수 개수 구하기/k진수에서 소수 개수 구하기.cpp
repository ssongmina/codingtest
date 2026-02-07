#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string go(int n, int k){
    string str = "";
    while(n > 0){
        str += to_string(n % k);
        n /= k;
    }
    reverse(str.begin(), str.end());
    return str;
}

vector<string> split(string str, string delimeter){
    long long pos;
    string token;
    vector<string> v;

    while((pos = str.find(delimeter)) != string::npos){
        token = str.substr(0, pos);
        if(!token.empty()) v.push_back(token);
        str.erase(0, pos + delimeter.size());
    }

    if(!str.empty()) v.push_back(str);
    return v;
}

bool isPrime(long long n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    for(long long i = 3; i * i <= n; i += 2){
        if(n % i == 0) return false;
    }
    return true;
}

int check(vector<string> v){
    int cnt = 0;
    for(auto &s : v){
        long long num = stoll(s);
        if(isPrime(num)) cnt++;
    }
    return cnt;
}

int solution(int n, int k) {
    string str = go(n, k);
    vector<string> v = split(str, "0");
    return check(v);
}
