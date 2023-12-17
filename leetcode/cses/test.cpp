#include <bitset>
#include <iostream>


using namespace std;
int main()
{

    // int x = 0;
    // x |= 1 << 1;
    // x |= 1 << 3;
    // x |= 1 << 4;
    // x |= 1 << 8;

    // std::cout << x << " with " << __builtin_popcount(x) << " elements" <<
    // endl;

    // for (int i = 0; i < 32; ++i) {
    //     if (x & (1 << i))
    //         cout << i << ' ';
    // }
    // cout << endl;

    // while (x != 0) {
    //     int bits =  __builtin_ctz(x);
    //     cout << bits << ' ';
    //     x &= (x - 1);
    // }

    bitset<10> bits;
    bits[1] = bits[3] = bits[4] = bits[7] = 1;
    cout << bits.count() << '\n';
    for (int x = 0; x < 10; ++x)
    {
        if ((~bits).test(x))
            cout << x << ' ';
    }

    return 0;
}