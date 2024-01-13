#include <iostream>

using namespace std;

int main()
{


    int n;
    cin >> n;

    // 2**n
    unsigned long long res = 1;
    for (int i = 0; i < n; ++i)
    {
        res = (res * 2ull) % (1'000'000'007);
    }

    cout << res;

}