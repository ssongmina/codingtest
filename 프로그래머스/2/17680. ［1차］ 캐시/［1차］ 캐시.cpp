#include <bits/stdc++.h>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    unordered_set<string> st;
    list<string> cache; // 순차 접근만 가능
    for(int i=0; i<cities.size(); i++){
        string s = cities[i];
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        if(cacheSize == 0){
            return cities.size() * 5;
        }
        if(st.count(s) == 1){ // 캐시에 존재
            answer += 1;
            cache.remove(s);
            cache.push_back(s);
        }
        else{ // 캐시에 존재 x
            answer += 5;
            cache.push_back(s);
            st.insert(s);
            if(cache.size() > cacheSize){
                st.erase(cache.front());
                cache.pop_front();
            }
        }
    }
    return answer;
}