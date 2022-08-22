#include "../../common/lib.hpp"
#include <algorithm>
#include <limits>

using namespace std;

vector<int> parse(istream &input) {
  vector<int> res;

  for (string line; getline(input, line);) {
    res.push_back(stoi(line));
  }

  return res;
}

int count_increasing(vector<int> *input) {
  return count_if(input->begin(), input->end(),
                  [prev = numeric_limits<int>::max()](const int &curr) mutable {
                    bool res = curr > prev;
                    prev = curr;
                    return res;
                  });
}

int count_increasing_groups(vector<int> *input) {
  vector<int> groups(input->size(), 0);
  for (size_t i = 0; i < input->size() - 2; i += 1) {
    groups.at(i) = input->at(i) + input->at(i + 1) + input->at(i + 2);
  }

  return count_increasing(&groups);
}

int part1(istream &input) {
  auto data = parse(input);
  return count_increasing(&data);
}

int part2(istream &input) {
  auto data = parse(input);
  return count_increasing_groups(&data);
}
