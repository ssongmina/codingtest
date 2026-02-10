#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;

bool check(int y, int x, int n){
    int a = v[y][x];
    for(int i = y; i < y + n; i++){
        for(int j = x; j < x + n; j++){
            if(a != v[i][j]) return false;
        }
    }
    return true;
}

pair<int,int> go(int y, int x, int n){
    if(n == 1){
        return v[y][x] == 1 ? make_pair(0, 1) : make_pair(1, 0);
    }

    pair<int,int> p = {0, 0};

    if(!check(y, x, n)){
        auto t1 = go(y, x, n/2);
        auto t2 = go(y + n/2, x, n/2);
        auto t3 = go(y, x + n/2, n/2);
        auto t4 = go(y + n/2, x + n/2, n/2);

        p.first += t1.first + t2.first + t3.first + t4.first;
        p.second += t1.second + t2.second + t3.second + t4.second;
    }
    else {
        if(v[y][x] == 1) p.second += 1;
        else p.first += 1;
    }

    return p;
}

vector<int> solution(vector<vector<int>> arr) {
    v = arr;
    int n = arr.size();

    pair<int,int> p = go(0, 0, n);

    vector<int> answer;
    answer.push_back(p.first);
    answer.push_back(p.second);

    return answer;
}
