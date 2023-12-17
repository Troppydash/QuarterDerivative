#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


int main() {

  string dna;
  cin >> dna;

  int longest = 0;
  int current = 1;
  char last_char = dna[0];

  for (int i = 1; i < dna.size(); ++i) {
    if (dna[i] == last_char)
      current += 1;
    else {
      longest = std::max(longest, current);
      current = 1;
    }

    last_char = dna[i];
  }

  longest = std::max(longest, current);
  cout << longest;

  return 0;
}