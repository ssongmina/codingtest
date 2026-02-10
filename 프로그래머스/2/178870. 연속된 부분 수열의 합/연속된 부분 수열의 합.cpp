#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int i=0, j=0, sum = sequence[i];
    int bestl = 0, bestr = 0, len = 987654321;
    while(i <= j && j<sequence.size()){
        if(sum == k){
            if(j-i+1 < len){
                len = j-i+1;
                bestl = i; bestr = j;   
            }
            j++;
            if (j < sequence.size()) sum += sequence[j];
        }
        else if(sum < k){
            j++;
            if (j < sequence.size()) sum += sequence[j];
        }
        else{
            sum -= sequence[i++];
        }
    }
    return {bestl, bestr};
}