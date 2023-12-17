#include <iostream>
#include <stdint.h>

using namespace std;

int main() 
{
    uint64_t n;
    cin >> n;

    // O(n)
    uint64_t sum = 0ull;
    uint64_t i;
    while (cin >> i)
    {
        sum += i;
    }

    // O(1)
    uint64_t expected = (1ull+n) * n / 2ull;

    // O(1)
    cout << expected - sum;
    return 0; 
}