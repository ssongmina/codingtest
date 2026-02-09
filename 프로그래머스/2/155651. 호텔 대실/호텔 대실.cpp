#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[1600];

int changee(string str){
    int h = stoi(str.substr(0,2));
    int m = stoi(str.substr(3,2));
    return h*60 + m;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    memset(arr, 0, sizeof(arr));
    for(int i=0; i<book_time.size(); i++){
        int start = changee(book_time[i][0]);
        int end = changee(book_time[i][1]) + 10;
        arr[start]++;
        arr[end]--;
    }
    int cur = 0;
    for(int i=0; i<1600; i++){
        cur += arr[i];
        answer = max(cur, answer);
    }
    return answer;
}