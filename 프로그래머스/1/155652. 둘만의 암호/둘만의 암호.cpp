#include <bits/stdc++.h>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for(char c : s) {
        int count = 0;
        while(count < index) {
            c++;
            if(c > 'z')
                c = 'a';
            if(skip.find(c) == string::npos) {
                count++;
            }
        }
        answer += c;
    }
    return answer;
}