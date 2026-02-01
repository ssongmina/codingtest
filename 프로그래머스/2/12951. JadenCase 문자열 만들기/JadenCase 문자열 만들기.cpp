#include <string>
#include <vector>

using namespace std;

vector<string> split(string input, string delimeter){
    long long pos = 0;
    string token;
    vector<string> ret;
    while((pos = input.find(delimeter)) != string::npos){
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos+delimeter.size());
    }
    ret.push_back(input);
    return ret;
}

string solution(string s) {
    string answer = "";
    vector<string> v = split(s, " ");
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            if(j == 0){
                answer += toupper(v[i][j]);
            }
            else {
                answer += tolower(v[i][j]);
            }
        }
        if(i!=v.size()-1) answer += " ";
    }
    return answer;
}