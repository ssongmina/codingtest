#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int,int> r1;
    map<int,int> r2;
    r1[topping[0]]++;
    for(int i=1; i<topping.size(); i++){
        r2[topping[i]]++;
    }
    if(r1.size() == r2.size()) answer++;
    for(int i=1; i<topping.size(); i++){
        r1[topping[i]]++;
        r2[topping[i]]--;
        if(r2[topping[i]] == 0) r2.erase(topping[i]);
        if(r1.size() == r2.size()) answer++;
    }
    
    return answer;
}