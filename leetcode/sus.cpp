#include <csetjmp>
#include <iostream>

// a compliation of the sus things about c++

namespace gotos {
// goto works only within 1 scope
// longjmp works across scopes, destructors don't run
std::jmp_buf label;

// setjmp saves the register state, and std::longjmp restores them from the label
// hence how setjmp returns twice

void process()
{
    std::puts("Ran 1");
    std::longjmp(label, 1);
}

void test()
{
    // this returns twice (0 by default and 1 after std::longjmp)
    if (setjmp(label) == 0) {
        process();
    } else {
        std::puts("Ran 2");
    }
}
}   // namespace gotos

namespace UB {
    // INT_MIN / -1 overflows because there are more negative and positive integers
    // INT_MIN % -1 also overflows?
    // because the standard computes both a/b and a%b in one instruction, so if a/b is UB
    // , a%b is also UB.
}

// sizeof(+1)["23456"] == 1 because sizeof has a lower precedence than subscript. 

// how % works with negative dividends and divisors


int main()
{
    int test = (INT_MIN+1) / -1;
    printf("%d\n", test);
    return 0;
}