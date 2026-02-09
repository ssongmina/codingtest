#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt = 0;
bool flag = false;

void dfs(string str, string target){
    if(flag) return;
    
    if(str == target){
        flag = true;
        return ;
    }
    
    if(str.size() == 5) return ;
    
    char c[5] = {'A', 'E', 'I', 'O', 'U'};
    for(int i=0; i<5; i++){
        if(str.size() < 5){
            cnt++;
            dfs(str+c[i], target);
            if(flag) return ;
        }
    }
}

int solution(string word) {
    dfs("", word);
    cout << cnt << "\n";
    return cnt;
}