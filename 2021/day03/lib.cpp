#include "lib.hpp"
#include <algorithm>
#include <vector>

using namespace std;

int part1(istream &input) {
  size_t size = 0;
  int counts[sizeof(int) * 8] = {};

  for (string line; getline(input, line);) {
    size = max(size, line.size());

    for (size_t i = 0; i < size; i++) {
      if (line.at(i) == '1') {
        counts[size - i - 1] += 1;
      } else {
        counts[size - i - 1] -= 1;
      }
    }
  }

  int mask = 0;
  int gamma = 0;
  for (size_t i = 0; i < size; i++) {
    mask |= (1 << i);

    if (counts[i] >= 0) {
      gamma |= (1 << i);
    }
  }

  int epsilon = ~gamma & mask;

  return gamma * epsilon;
}

int find_rating(size_t nbits, bool most_frequent, vector<int>::iterator begin,
                vector<int>::iterator end) {
  if (end - begin == 1) {
    return *begin;
  }

  auto mid = find_if(begin, end, [at = nbits](const int &val) {
    return ((val >> (at - 1)) & 0b1) > 0;
  });

  size_t zeros = mid - begin;
  size_t ones = end - mid;

  return most_frequent
             ? (ones >= zeros
                    ? find_rating(nbits - 1, most_frequent, mid, end)
                    : find_rating(nbits - 1, most_frequent, begin, mid))
             : (zeros <= ones
                    ? find_rating(nbits - 1, most_frequent, begin, mid)
                    : find_rating(nbits - 1, most_frequent, mid, end));
}

int part2(istream &input) {
  // parse data
  size_t nbits = 0;
  vector<int> data;
  for (string line; getline(input, line);) {
    nbits = max(nbits, line.size());
    data.push_back(stoi(line, nullptr, 2));
  }

  sort(data.begin(), data.end());

  //
  int ogr = find_rating(nbits, true, data.begin(), data.end());
  int co2sr = find_rating(nbits, false, data.begin(), data.end());

  return ogr * co2sr;
};
