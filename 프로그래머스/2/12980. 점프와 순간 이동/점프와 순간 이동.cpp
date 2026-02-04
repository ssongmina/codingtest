#include <bits/stdc++.h>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while(n != 0){
        if(n % 2 != 0){
            ans++;
        }
        n /= 2;
        cout << n << "\n";
    }

    return ans;
}