#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

bool isPrime(int n){
    if(n < 2) return 0;
    if(n == 2) return 1;
    if(n%2 == 0) return 0;
    for(int i=3; i*i<=n; i++){
        if(n%i == 0) return 0;
    }
    return 1;
}

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    unordered_set<int> s;
    do{
        for(int i=0; i<numbers.size(); i++){
            s.insert(stoi(numbers.substr(0, i+1)));
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    for(int x : s){
        answer += isPrime(x);
    }
    cout << s.size() << "\n";
    return answer;
}