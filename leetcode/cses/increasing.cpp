#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int largest = -1;
    unsigned long long sum = 0ull;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;

        largest = std::max(largest, k);
        sum += largest - k;
    }

    cout << sum;

    return 0;
}