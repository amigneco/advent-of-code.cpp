#include "lib.hpp"
#include <algorithm>
#include <limits>

uint32_t count_increasing(std::vector<uint32_t> *input) {
  return std::count_if(
      input->begin(), input->end(),
      [prev = std::numeric_limits<uint32_t>::max()](uint32_t curr) mutable {
        bool res = curr > prev;
        prev = curr;
        return res;
      });
}

uint32_t count_increasing_groups(std::vector<uint32_t> *input) {
  std::vector<uint32_t> groups(input->size(), 0);
  for (uint32_t i = 0; i < input->size() - 2; i += 1) {
    groups.at(i) = input->at(i) + input->at(i + 1) + input->at(i + 2);
  }

  return count_increasing(&groups);
}
