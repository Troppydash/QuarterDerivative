#include <iostream>
using namespace std;

int main()
{
    unsigned long long i;
    cin >> i;

    while (true)
    {
        printf("%lld ", i);
        if (i == 1) break;
        if (i % 2 == 0)  i /= 2;
        else i = i * 3 + 1;
    }

    return 0;
}