#include <cmath>
#include <iostream>
#include <vector>

using ull = unsigned long long;
using namespace std;


ull count(int height, int width)
{
    // the new row counts, divide by 2 to remove the repeats
    ull row = (ull) width * (width - 1) / 2;
    if (height == 1) {
        return row;
    }

    ull smaller = count(height - 1, width);
    ull smaller_size = (ull) (height - 1) * (width);

    ull gap = width - 4;
    ull cross;
    if (height == 2) {
        cross = (smaller_size - 1) * 4 + gap * (smaller_size - 2);
    } else {
        cross = (smaller_size - 2) * 2 + (smaller_size - 3) * 2
            + gap * (smaller_size - 4);
    }

    return smaller + cross + row;
}

ull perms(int size)
{
    static int cache[] = { 0, 6, 28, 96 };
    if (size <= 3) {
        return cache[size - 1];
    }
    return count(size, size);
}

int main()
{
    int k;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        cout << perms(i + 1) << '\n';
    }
    return 0;
}