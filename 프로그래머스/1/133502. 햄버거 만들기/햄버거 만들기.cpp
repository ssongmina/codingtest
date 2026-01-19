#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> ingredient) {
    vector<int> st;
    int answer = 0;

    for(int x : ingredient) {
        st.push_back(x);
        if(st.size() >= 4) {
            int n = st.size();
            if(st[n-4] == 1 && st[n-3] == 2 &&
               st[n-2] == 3 && st[n-1] == 1) {

                for(int i = 0; i < 4; i++)
                    st.pop_back();

                answer++;
            }
        }
    }

    return answer;
}
