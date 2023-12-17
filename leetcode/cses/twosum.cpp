#include <iostream>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main()
{
    int n;
    cin >> n;

    ull total = (ull) n * (1 + n) / 2;
    if (total % 2 == 1) {
        cout << "NO";
        return 0;
    }

    cout << "YES" << '\n';
    ull target = total / 2;
    // a greedy algo because the series can always make target with selections
    // like
    // ... x ... abcd

    int upper = n + 1;
    while (target >= upper) {
        // keep selecting until the leftover is under upper and selectable
        upper -= 1;
        target -= upper;
    }
    // upper is "a", the first element in the grouped part of the first set
    // target is the leftover "x"

    // print x ... abcd
    cout << n + 2 - upper << '\n';
    cout << target << ' ';
    for (int i = upper; i <= n; ++i)
        cout << i << ' ';
    cout << '\n';

    // print 1..(a-1) excluding "x"
    cout << upper - 2 << '\n';
    for (int i = 1; i < upper; ++i) {
        if (i == target)
            continue;
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}