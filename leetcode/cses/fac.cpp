#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unsigned long long count = 0;
    for (int k = 5; k <= n; k *= 5) {
        count += n / k;
    }

    cout << count;
}