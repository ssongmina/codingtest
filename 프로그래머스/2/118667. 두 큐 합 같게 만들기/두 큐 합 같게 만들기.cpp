#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0LL);

    long long total = sum1 + sum2;
    if (total % 2 != 0) return -1;

    vector<int> q;
    q.insert(q.end(), queue1.begin(), queue1.end());
    q.insert(q.end(), queue2.begin(), queue2.end());

    int n = queue1.size();
    int size = 2 * n;

    int i = 0, j = 0;
    int count = 0;
    int limit = n * 4;

    while (count <= limit) {
        if (sum1 == sum2) return count;

        if (sum1 > sum2) {
            int val = q[i % size];
            sum1 -= val;
            sum2 += val;
            i++;
        } 
        else {
            int val = q[(n + j) % size];
            sum1 += val;
            sum2 -= val;
            j++;
        }

        count++;
    }

    return -1;
}
