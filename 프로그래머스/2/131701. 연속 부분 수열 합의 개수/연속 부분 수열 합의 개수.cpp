#include <bits/stdc++.h>

using namespace std;
set<int> num;

int solution(vector<int> elements) {
    vector<int> ext = elements;
    ext.insert(ext.end(), elements.begin(), elements.end());
    
    for(int i=1; i<=elements.size(); i++){
        int sum = 0;
        for(int j=0; j<i; j++){
            sum += ext[j];
        }
        num.insert(sum);
        
        for(int j=i; j<i+elements.size()-1; j++){
            sum += ext[j] - ext[j-i];
            num.insert(sum);
        }
    }
    
    return num.size();
}