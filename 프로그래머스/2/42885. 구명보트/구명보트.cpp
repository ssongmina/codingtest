#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, i=0, j=people.size()-1;
    sort(people.begin(), people.end());
    while(i <= j){
        if(people[j]+people[i] > limit){
            answer++;
            j--;
        }
        else{
            answer++;
            j--; i++;
        }
    }
    return answer;
}