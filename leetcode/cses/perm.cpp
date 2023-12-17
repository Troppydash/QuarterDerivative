#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1;
        return 0;
    }

    int k = 1;
    vector<int> numbers { k };
    unordered_set<int> counted { k };

    while (true) {
        if (numbers.size() >= n)
            break;

        k = k + 2;
        if (k >= n)
        {
            k = 0;
        }

        if (abs(numbers.back() - k) == 1) {
            cout << "NO SOLUTION";
            return 0;
        }

        counted.emplace(k);
        numbers.push_back(k);
    }

    for (auto i : numbers) {
        cout << i + 1 << ' ';
    }
    return 0;
}