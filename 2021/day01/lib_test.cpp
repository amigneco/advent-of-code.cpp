#include "lib.hpp"
#include <gtest/gtest.h>
#include <vector>

using namespace std;

TEST(day01, part1) {
  vector<uint32_t> values = {199, 200, 208, 210, 200, 207, 240, 269, 260, 263};

  EXPECT_EQ(count_increasing(&values), 7);
}

TEST(day01, part2) {
  vector<uint32_t> values = {199, 200, 208, 210, 200, 207, 240, 269, 260, 263};

  EXPECT_EQ(count_increasing_groups(&values), 5);
}
