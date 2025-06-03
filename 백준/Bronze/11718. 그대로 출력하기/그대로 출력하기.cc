#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) { // EOF 전까지 한 줄씩 입력
        cout << line << '\n';
    }
    return 0;
}
