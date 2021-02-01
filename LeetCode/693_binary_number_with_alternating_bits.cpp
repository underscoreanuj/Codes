// bitwise approach

class Solution {
public:
  bool hasAlternatingBits(int n) {
    long long int x = n;
    x ^= (x >> 1);
    return (x & (x + 1)) == 0;
  }
};

// standard approach

class Solution {
public:
  bool hasAlternatingBits(int n) {
    int prev = n % 2;
    n >>= 1;

    while (n) {
      if (prev == n % 2)
        return false;
      prev = n % 2;
      n >>= 1;
    }

    return true;
  }
};
