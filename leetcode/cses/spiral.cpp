#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

unsigned long long index(unsigned long long row, unsigned long long col)
{
    if (row > col) {
        if (row % 2 == 0) {
            unsigned long long upper = row * row;
            return upper - col + 1;
        } else {
            unsigned long long lower = (row - 1) * (row - 1);
            return lower + col;
        }
    } else {
        if (col % 2 == 1) {
            unsigned long long upper = col * col;
            return upper - row + 1;
        } else {
            unsigned long long lower = (col - 1) * (col - 1);
            return lower + row;
        }
    }
}

int main()
{
    int tests;
    cin >> tests;

    int y, x;
    for (int i = 0; i < tests; ++i) {
        cin >> y >> x;

        cout << index(y, x) << '\n';
    }

    return 0;
}