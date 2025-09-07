#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int Max;
int arr[1001];
int cnt[1001];

void init();
void input();
void Solve();

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}

void Solve()
{
    for (int i = 0; i < N; i++)
    {
        int Standard = arr[i];
        memset(cnt, 0, sizeof(cnt));

        int Max_left = 0;
        int Max_right = 0;

        // left (0 ~ i-1)
        for (int j = i - 1; j >= 0; j--)
        {
            int Picked = arr[j];

            if (Picked >= Standard)
                continue;

            int temp = 0;

            // j+1 ~ i
            for (int t = j + 1; t <= i; t++)
            {
                if (Picked < arr[t])
                {
                    temp = max(temp, cnt[t] + 1);
                }
            }
            cnt[j] = temp;
            Max_left = max(Max_left, temp);
        }

        // right (i+1 ~ N-1)
        for (int j = i + 1; j < N; j++)
        {
            int Picked = arr[j];

            if (Picked >= Standard)
                continue;

            int temp = 0;

            // j-1 ~ i
            for (int t = j - 1; t >= i; t--)
            {
                if (Picked < arr[t])
                {
                    temp = max(temp, cnt[t] + 1);
                }
            }
            cnt[j] = temp;
            Max_right = max(Max_right, temp);
        }

        Max = max(Max, Max_left + Max_right);
    }
    cout << Max + 1;
}

int main()
{
    init();
    input();
    Solve();

    return 0;
}