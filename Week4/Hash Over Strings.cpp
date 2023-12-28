#include <iostream>
using namespace std;

const int MAX_N = 200;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, M;
    cin >> n >> M;

    int a[MAX_N] = {1};
    for (int i = 1; i < MAX_N; i++)
    {
        a[i] = (256 * a[i - 1]) % M;
    }

    while (n--)
    {
        string text;
        cin >> text;
        int result = 0;
        int len = text.length();
        for (int i = 0; i < len; i++)
        {
            result += text[i] * a[len - 1 - i] % M;
        }
        cout << result % M << '\n';
    }

    return 0;
}
