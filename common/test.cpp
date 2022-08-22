#include "lib.hpp"
#include <fstream>
#include <gtest/gtest.h>

using namespace std;

TEST(lib, part1) {
  ifstream input("example.txt");
  EXPECT_EQ(part1(input), ${PART_1_RESULT});
}

TEST(lib, part2) {
  ifstream input("example.txt");
  EXPECT_EQ(part2(input), ${PART_2_RESULT});
}
